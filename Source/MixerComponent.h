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
    
    juce::TextButton load_chn1;
    
    juce::Slider trim_chn1;
    juce::Slider hi_chn1;
    juce::Slider med_chn1;
    juce::Slider lo_chn1;
    juce::Slider clr_chn1;
    juce::Slider fx_chn1;
    
    juce::TextButton fxtoggle_chn1;
    juce::TextButton cuetoggle_chn1;
    
    // Volume fader
    juce::Slider volFader;
    
    //std::unique_ptr<juce::FileChooser> chooser;
    //juce::AudioFormatManager formatManager;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
    

};
