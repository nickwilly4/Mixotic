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
    
    // ========Channel 1========
    // Load
    juce::TextButton load_chn1;
    // Dials
    juce::Slider trim_chn1;
    juce::Slider hi_chn1;
    juce::Slider med_chn1;
    juce::Slider lo_chn1;
    juce::Slider clr_chn1;
    juce::Slider fx_chn1;
    // Toggle Buttons
    juce::TextButton fxtoggle_chn1;
    juce::TextButton cuetoggle_chn1;
    // Volume Fader
    juce::Slider volFader_chn1;
    // ========End Channel 1========
    
    // ========Channel 2========
    // Load
    juce::TextButton load_chn2;
    // Dials
    juce::Slider trim_chn2;
    juce::Slider hi_chn2;
    juce::Slider med_chn2;
    juce::Slider lo_chn2;
    juce::Slider clr_chn2;
    juce::Slider fx_chn2;
    // Toggle Buttons
    juce::TextButton fxtoggle_chn2;
    juce::TextButton cuetoggle_chn2;
    // Volume Fader
    juce::Slider volFader_chn2;
    // ========End Channel 2========
    
    // ========Channel 3========
    // Load
    juce::TextButton load_chn3;
    // Dials
    juce::Slider trim_chn3;
    juce::Slider hi_chn3;
    juce::Slider med_chn3;
    juce::Slider lo_chn3;
    juce::Slider clr_chn3;
    juce::Slider fx_chn3;
    // Toggle Buttons
    juce::TextButton fxtoggle_chn3;
    juce::TextButton cuetoggle_chn3;
    // Volume Fader
    juce::Slider volFader_chn3;
    // ========End Channel 3========
    
    // ========Channel 4========
    // Load
    juce::TextButton load_chn4;
    // Dials
    juce::Slider trim_chn4;
    juce::Slider hi_chn4;
    juce::Slider med_chn4;
    juce::Slider lo_chn4;
    juce::Slider clr_chn4;
    juce::Slider fx_chn4;
    // Toggle Buttons
    juce::TextButton fxtoggle_chn4;
    juce::TextButton cuetoggle_chn4;
    // Volume Fader
    juce::Slider volFader_chn4;
    // ========End Channel 4========
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
    

};
