/*
  ==============================================================================

 EQControlColumn.h
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

class EQControlColumn  : public juce::Component {
    std::string columnNum;
public:
    EQControlColumn(const std::string& columnNumber);
    ~EQControlColumn() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    // Load
    juce::TextButton load_chn;
    // Dials
    juce::Slider trim_chn;
    juce::Slider hi_chn;
    juce::Slider med_chn;
    juce::Slider lo_chn;
    juce::Slider clr_chn;
    juce::Slider fx_chn;
    // Toggle Buttons
    juce::TextButton fxtoggle_chn;
    juce::TextButton cuetoggle_chn;
    // Volume Fader
    juce::Slider volFader_chn;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQControlColumn)
};
