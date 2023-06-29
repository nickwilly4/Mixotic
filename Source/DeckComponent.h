/*
  ==============================================================================
 
    DeckComponent.h
    Created: 21 Jun 2023 5:37:24pm
    Author:  Nick Aichholz
 
  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//==============================================================================
class MainComponent; // Forward declaration to avoid circular dependency

class DeckComponent  : public juce::Component, public juce::Slider::Listener
{
    std::string channelNum;
    MainComponent& mainComponent; // Add this member variable
    
//==============================================================================
public:
    enum Mode { Mode1, Mode2 };
    DeckComponent(const std::string& channelNumber, MainComponent& mainComponentRef);
    ~DeckComponent() override;

    //==============================================================================
    void setMode(Mode newMode);
    void paint (juce::Graphics&) override;
    void resized() override;
    
    Mode getMode() const;

//==============================================================================
    juce::Slider channelSlide;
private:
    Mode currentMode;
    juce::Colour backgroundColor;
    
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
    
    // Loop
    juce::TextButton loopIn;
        juce::Label loopInLabel;
    juce::TextButton loopOut;
        juce::Label loopOutLabel;
    juce::TextButton loopRe;
        juce::Label loopReLabel;
    juce::TextButton loopHalf;
        juce::Label loopHalfLabel;
    juce::TextButton loopDouble;
        juce::Label loopDoubleLabel;
    
    // Channel switch
    //juce::Slider channelSlide;
    void sliderValueChanged(juce::Slider* slider) override;
        juce::Label channelLabel;
    
    juce::Slider jog;
    
    // Volume fader
    juce::Slider volFader;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckComponent)
};
