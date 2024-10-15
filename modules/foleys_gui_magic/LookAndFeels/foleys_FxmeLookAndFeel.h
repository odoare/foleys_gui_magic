#pragma once

namespace foleys
{

class FxmeKnobLookAndFeel : public JuceLookAndFeel_V4
{
public:
  FxmeKnobLookAndFeel() = default;

  void drawRotarySlider(juce::Graphics&, 
          int x, int y, 
          int width,
          int height, 
          float sliderPos, 
          float rotaryStartAngle, 
          float rotaryEndAngle, 
          juce::Slider&) override;

  // juce::Slider::SliderLayout getSliderLayout (juce::Slider&) override;


  // void drawLabel(juce::Graphics&, juce::Label&) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FxmeKnobLookAndFeel)

};

// class FxmeButtonLookAndFeel : public juce::LookAndFeel_V4
// {
// public:
//   FxmeButtonLookAndFeel() = default;
  
//   // Toggle button overrides
//   // -----------------------

//   void drawToggleButton(juce::Graphics &g,
//                             juce::ToggleButton &b,
//                             bool 	shouldDrawButtonAsHighlighted,
//                             bool 	shouldDrawButtonAsDown ) override;

//   private:
//   JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FxmeButtonLookAndFeel)
// };

}

