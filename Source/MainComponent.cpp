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
    
    // Pads
    auto padColor = juce::Colours::red;
    auto padToggleState = true;
    addAndMakeVisible(padBottom1);
    padBottom1.setClickingTogglesState(padToggleState);
    padBottom1.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padBottom2);
    padBottom2.setClickingTogglesState(padToggleState);
    padBottom2.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padBottom3);
    padBottom3.setClickingTogglesState(padToggleState);
    padBottom3.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padBottom4);
    padBottom4.setClickingTogglesState(padToggleState);
    padBottom4.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop1);
    padTop1.setClickingTogglesState(padToggleState);
    padTop1.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop2);
    padTop2.setClickingTogglesState(padToggleState);
    padTop2.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop3);
    padTop3.setClickingTogglesState(padToggleState);
    padTop3.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop4);
    padTop4.setClickingTogglesState(padToggleState);
    padTop4.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
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
    auto windowWidth = 600;
    auto windowHeight = 800;
    auto space = 10;
    auto biggerSpace = 2*space;
    
    auto buttonWidth = 50;
    auto buttonHeight = 50;
    
    auto padWidth = 60;
    auto padHeight = 60;
    
    // Play Pause Button
    playPause.setBounds(margin, windowHeight-margin-buttonHeight, buttonWidth, buttonHeight);
    
    // Cue Button
    cue.setBounds(margin, windowHeight-playPause.getHeight()-margin-space-buttonHeight, buttonWidth, buttonHeight);
    
    // Pads
    padBottom1.setBounds(margin+buttonWidth+biggerSpace, windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom2.setBounds(margin+buttonWidth+biggerSpace+padWidth+space, windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom3.setBounds(margin+buttonWidth+biggerSpace+2*(padWidth+space), windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom4.setBounds(margin+buttonWidth+biggerSpace+3*(padWidth+space), windowHeight-margin-padHeight, padWidth, padHeight);
    
    padTop1.setBounds(margin+buttonWidth+biggerSpace, windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop2.setBounds(margin+buttonWidth+biggerSpace+padWidth+space, windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop3.setBounds(margin+buttonWidth+biggerSpace+2*(padWidth+space), windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop4.setBounds(margin+buttonWidth+biggerSpace+3*(padWidth+space), windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
}
