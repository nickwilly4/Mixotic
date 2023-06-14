#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::TextButton playPause;
    juce::TextButton cue;
    
    // Pads
    juce::TextButton padBottom1;
    juce::TextButton padBottom2;
    juce::TextButton padBottom3;
    juce::TextButton padBottom4;
    juce::TextButton padTop1;
    juce::TextButton padTop2;
    juce::TextButton padTop3;
    juce::TextButton padTop4;
    
    // Pad Modes
    juce::TextButton padMode1;
    juce::TextButton padMode2;
    juce::TextButton padMode3;
    juce::TextButton padMode4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
