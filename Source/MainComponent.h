#pragma once

#include <JuceHeader.h>
#include "DeckComponent.h"
#include "EQControlColumn.h"


class MainComponent  : public juce::AudioAppComponent,
                       public juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    
    //special
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    
    void onEQControlColumnLoadClicked(const std::string& columnNumber);
    void playButtonClicked(const std::string& channelNumber);
    
private:
    DeckComponent leftDeckComponent;
    DeckComponent rightDeckComponent;

    EQControlColumn channel1;
    EQControlColumn channel2;
    EQControlColumn channel3;
    EQControlColumn channel4;
    
    // load functionality
    enum TransportState
    {
        Stopped,
        Starting,
        Playing,
        Pausing,
        Paused,
        Stopping
    };

    void changeState(TransportState newState);

    std::unique_ptr<juce::FileChooser> chooser;

    juce::AudioFormatManager formatManager;
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;
    TransportState state;
    //
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
