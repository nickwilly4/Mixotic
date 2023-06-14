#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Window
    auto windowWidth = 600;
    auto windowHeight = 800;
    setSize (windowWidth, windowHeight);
    
    // Play Pause Button
    addAndMakeVisible(playPause);
    playPause.setButtonText("Play");
    playPause.setClickingTogglesState(true);
    playPause.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
    playPause.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    playPause.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    playPause.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Cue Button
    addAndMakeVisible(cue);
    cue.setButtonText("Cue");
    cue.setClickingTogglesState(true);
    cue.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
    cue.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cue.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cue.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (48.0f));
    g.setColour (juce::Colours::green);
    g.drawText ("New Graphics!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.\
    
    // Convenient
    auto margin = 10;
    auto buttonWidth = 50;
    auto buttonHeight = 50;
    auto windowWidth = 600;
    auto windowHeight = 800;
    
    // Play Pause Button
    playPause.setBounds(margin, windowHeight-margin-buttonHeight, buttonWidth, buttonHeight);
    
    // Cue Button
    cue.setBounds(margin, windowHeight-playPause.getHeight()-margin-margin-buttonHeight, buttonWidth, buttonHeight);
}
