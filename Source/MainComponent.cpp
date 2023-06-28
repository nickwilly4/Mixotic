#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
    : channel1("1", *this), channel2("2", *this), channel3("3", *this), channel4("4", *this), leftDeckComponent("1-3"), rightDeckComponent("2-4")
{
    setSize (leftDeckComponent.getWidth()*2+80*4, 700);
    
    addAndMakeVisible(leftDeckComponent);
    addAndMakeVisible(rightDeckComponent);
    addAndMakeVisible(channel1);
    addAndMakeVisible(channel2);
    addAndMakeVisible(channel3);
    addAndMakeVisible(channel4);
    
}
MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::onEQControlColumnLoadClicked(const std::string& columnNumber) {
    // Do something when the Load button in EQControlColumn is clicked
    std::cout << "Load button in EQ Control Column " << columnNumber << " was clicked!" << std::endl;
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey); // Clear the background
}

void MainComponent::resized()
{
    //auto area = getLocalBounds();
    //auto deckAreaWidth = area.getWidth() / 3;
    leftDeckComponent.setBounds(0, 0, leftDeckComponent.getWidth(), leftDeckComponent.getHeight());
    rightDeckComponent.setBounds(leftDeckComponent.getWidth()+80*4, 0, rightDeckComponent.getWidth(), leftDeckComponent.getHeight());
    
    channel1.setBounds(leftDeckComponent.getWidth()+80, 0, channel1.getWidth(), channel1.getHeight());
    channel2.setBounds(leftDeckComponent.getWidth()+160, 0, channel2.getWidth(), channel2.getHeight());
    channel3.setBounds(leftDeckComponent.getWidth()+0, 0, channel3.getWidth(), channel3.getHeight());
    channel4.setBounds(leftDeckComponent.getWidth()+240, 0, channel4.getWidth(), channel4.getHeight());
}
