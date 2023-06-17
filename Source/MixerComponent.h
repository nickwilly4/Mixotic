/*
  ==============================================================================

    MixerComponent.h
    Created: 16 Jun 2023 8:17:18pm
    Author:  Nick Aichholz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
//std::unique_ptr<juce::FileChooser> chooser;
//juce::AudioFormatManager formatManager;

class MixerComponent  : public juce::Component//,public juce::ChangeListener,public juce::Timer
{
public:
    //==============================================================================
    MixerComponent();
    ~MixerComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    //formatManager.registerBasicFormats();
    //transportSource.addChangeListener (this);
    
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
    juce::Slider channelSlide;
        juce::Label channelLabel;

    
    // Volume fader
    juce::Slider volFader;
    
    //std::unique_ptr<juce::FileChooser> chooser;
    //juce::AudioFormatManager formatManager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
    

};
