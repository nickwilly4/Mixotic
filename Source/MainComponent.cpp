/*
  ==============================================================================

    MainComponent.cpp
    Created: 13 Jun 2023 5:37:24pm
    Author:  Nick Aichholz

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
    :   channel1("1", *this),
        channel2("2", *this),
        channel3("3", *this),
        channel4("4", *this),
        Deck1("1", *this),
        Deck2("2", *this),
        Deck3("3", *this),
        Deck4("4", *this)
{
    setSize (Deck1.getWidth()*2+80*4, 700);
    
    addAndMakeVisible(Deck1);
    addAndMakeVisible(Deck2);
    //addAndMakeVisible(Deck3);
    //addAndMakeVisible(Deck4);
    addAndMakeVisible(channel1);
    addAndMakeVisible(channel2);
    addAndMakeVisible(channel3);
    addAndMakeVisible(channel4);
    
    formatManager.registerBasicFormats();
    transportSource.addChangeListener(this);

    setAudioChannels(2, 2);
    
}
MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}


void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource.get() == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
        return;
    }

    transportSource.getNextAudioBlock(bufferToFill);
}
void MainComponent::releaseResources()
{
    transportSource.releaseResources();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey); // Clear the background
    //if (Deck3.channelSlide.getValue() == 1) {
    //    Deck3.setBounds(Deck1.getHeight(), 0, Deck1.getWidth(), Deck1.getHeight());
    //    repaint();
    //}
}

void MainComponent::resized()
{
    Deck1.setBounds(0, 0, Deck1.getWidth(), Deck1.getHeight());
    std::cout << Deck1.getHeight();
    //Deck3.setBounds(0, 0, Deck1.getWidth(), Deck1.getHeight());

    Deck2.setBounds(Deck1.getWidth()+80*4, 0, Deck2.getWidth(), Deck1.getHeight());
    //Deck4.setBounds(Deck1.getWidth()+80*4, 0, Deck2.getWidth(), Deck1.getHeight());

    channel1.setBounds(Deck1.getWidth()+80, 0, channel1.getWidth(), channel1.getHeight());
    channel2.setBounds(Deck1.getWidth()+160, 0, channel2.getWidth(), channel2.getHeight());
    channel3.setBounds(Deck1.getWidth()+0, 0, channel3.getWidth(), channel3.getHeight());
    channel4.setBounds(Deck1.getWidth()+240, 0, channel4.getWidth(), channel4.getHeight());

}
//==============================================================================
void MainComponent::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (source == &transportSource)
    {
        if (transportSource.isPlaying())
            changeState(Playing);
        else if ((state == Stopping) || (state == Playing))
            changeState(Stopped);
        else if (state == Pausing)
            changeState(Paused);
    }
}

//void MainComponent::onEQControlColumnLoadClicked(const std::string& columnNumber) {
//    // Do something when the Load button in EQControlColumn is clicked
//    std::cout << "Load button in EQ Control Column " << columnNumber << " was clicked!" << std::endl;
//}

void MainComponent::onEQControlColumnLoadClicked(const std::string& columnNumber)
{
    std::cout << "Load button in EQ Control Column " << columnNumber << " was clicked!" << std::endl;
    chooser = std::make_unique<juce::FileChooser>("Select a Wave file to play...",
                                                 juce::File{},
                                                 "*.wav");
    auto chooserFlags = juce::FileBrowserComponent::openMode |
                        juce::FileBrowserComponent::canSelectFiles;

    chooser->launchAsync(chooserFlags, [this](const juce::FileChooser& fc)
    {
        auto file = fc.getResult();

        if (file != juce::File{})
        {
            auto* reader = formatManager.createReaderFor(file);

            if (reader != nullptr)
            {
                auto newSource = std::make_unique<juce::AudioFormatReaderSource>(reader, true);
                transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
                //playButton.setEnabled(true);
                readerSource.reset(newSource.release());
            }
        }
    });
}

void MainComponent::changeState(TransportState newState)
{
    if (state != newState)
    {
        state = newState;

        switch (state)
        {
        case Stopped:
            transportSource.setPosition(0.0);
            break;

        case Starting:
            transportSource.start();
            break;

        case Playing:
            break;

        case Pausing:
            transportSource.stop();
            break;

        case Paused:
            break;

        case Stopping:
            transportSource.stop();
            break;
        }
    }
}

void MainComponent::playButtonClicked(const std::string& channelNumber)
{
    if ((state == Stopped) || (state == Paused))
        changeState(Starting);
    else if (state == Playing)
        changeState(Pausing);
}
