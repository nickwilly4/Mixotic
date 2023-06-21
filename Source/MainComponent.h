#pragma once

#include <JuceHeader.h>
//#include "LeftDeckComponent.h"
//#include "RightDeckComponent.h"
#include "DeckComponent.h"
#include "EQControlColumn.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    DeckComponent leftDeckComponent;
    DeckComponent rightDeckComponent;

    EQControlColumn channel1;
    EQControlColumn channel2;
    EQControlColumn channel3;
    EQControlColumn channel4;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
