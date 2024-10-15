#include "FxmeLookAndFeel.h"

namespace foleys
{

void FxmeKnobLookAndFeel::drawRotarySlider(juce::Graphics &g, 
          int x, int y, 
          int width,
          int height, 
          float sliderPos, 
          float rotaryStartAngle, 
          float rotaryEndAngle, 
          juce::Slider &slider) 
  {
    float diameter = 0.85*juce::jmin(width,height);
    float radius = diameter * 0.5;
    float centreX = x + width * 0.5;
    float centreY = y + height * 0.5;
    float rx = centreX - radius;
    float ry = centreY - radius;
    float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle-rotaryStartAngle));
    float thickness = diameter/12;

    juce::Rectangle<float> dialArea(rx,ry,diameter,diameter);
    g.setColour(slider.findColour(juce::Slider::rotarySliderFillColourId).brighter(2.f));
    g.drawEllipse(dialArea.reduced(thickness).translated(0.f,-thickness*0.05f),thickness*0.15f);
    g.setColour(slider.findColour(juce::Slider::rotarySliderFillColourId));
    g.fillEllipse(dialArea.reduced(thickness));
    
    g.setColour(slider.findColour(juce::Slider::thumbColourId));
    juce::Path dialTick;
    juce::Rectangle<int> rect(0.f,-radius+thickness,thickness,radius*0.4);
    dialTick.addRectangle(rect);
    g.fillPath(dialTick,juce::AffineTransform::rotation(angle).translated(centreX,centreY));

    g.setColour(slider.findColour(juce::Slider::trackColourId));
    juce::Path arc1;
    arc1.addArc(centreX-diameter/2, centreY-diameter/2, diameter, diameter, rotaryStartAngle, rotaryEndAngle, true);
    g.strokePath(arc1, juce::PathStrokeType(thickness));
    g.setColour(slider.findColour(juce::Slider::rotarySliderOutlineColourId));
    juce::Path arc2, arc3;
    arc2.addArc(centreX-diameter/2, centreY-diameter/2, diameter, diameter, rotaryStartAngle, angle, true);
    juce::PathStrokeType path{thickness, juce::PathStrokeType::JointStyle::curved, juce::PathStrokeType::EndCapStyle::rounded};
    g.strokePath(arc2, path);
    
  };

  // juce::Slider::SliderLayout FxmeKnobLookAndFeel::getSliderLayout (juce::Slider& slider)
  // {
  //   auto localBounds = slider.getLocalBounds().reduced(5).toFloat();

  //   juce::Slider::SliderLayout layout;
  //   layout.sliderBounds = slider.getLocalBounds().reduced(5);

  //   // Text blow the knob
  //   layout.textBoxBounds = slider.getLocalBounds().withHeight(localBounds.getHeight()*0.25);
  //   layout.textBoxBounds.translate(0,localBounds.getHeight()*0.9f);

  //   return layout;
  // }

  // void FxmeKnobLookAndFeel::drawLabel(juce::Graphics &g, juce::Label &label)
  // {
  //   g.setColour(juce::Colours::white);
    
  //   auto labelArea{label.getLocalBounds().toFloat()};
  //   g.setFont(labelArea.getHeight() * 0.7f);
  //   auto center = labelArea.getCentre();
  //   auto bottom = labelArea.getBottom();

  //   juce::String labelToDisplay = juce::String(label.getText());
    
  //   g.drawSingleLineText(labelToDisplay,
  //                         juce::roundToInt(center.x + g.getCurrentFont().getHorizontalScale()),
  //                         juce::roundToInt(center.y + 1.4*g.getCurrentFont().getDescent()),
  //                         juce::Justification::horizontallyCentred);
 
  //   }



// void FxmeButtonLookAndFeel::drawToggleButton(juce::Graphics &g,
//                             juce::ToggleButton &b,
//                             bool 	shouldDrawButtonAsHighlighted,
//                             bool 	shouldDrawButtonAsDown )
//   {
//     auto bounds = b.getLocalBounds();
//     auto isDown = b.getToggleState();
//     auto col = b.findColour(0);
//     float t;
//     float w = bounds.getWidth()*.1f;

//     if (isDown)
//       g.setColour(col.brighter(0.3f));
//     else
//       g.setColour(col.darker(.8f));
//     g.fillRoundedRectangle(bounds.toFloat(),w*2);

//     if (isDown)
//     {
//       g.setColour(juce::Colours::white);
//       t = w*.5f;
//     }
//       else
//     {
//       g.setColour(juce::Colours::black);
//       t = w;
//     }
//     g.drawRoundedRectangle(bounds.toFloat(),w*2,t);
//   }


}

