#include "sketchpad.h"
#include <string>
namespace worldmap {

using glm::vec2;

  Sketchpad::Sketchpad()
  {
    ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
  }

  void Sketchpad::draw() {

    land.Display(command, person, start);
    ci::gl::drawString(to_string(TC.getTimerMilliSec()), vec2(350, 750), ci::Color("blue"));

    //check the end
    if(TC.getTimerSecond() > 180) {
      ci::gl::drawString("You lose the game", vec2(450, 750), ci::Color("blue"));
    }
    else {
      if(land.Europe->getInfectedNum() == land.Europe->getTotalNum() &&
          land.SouthAmerica->getInfectedNum() == land.SouthAmerica->getTotalNum() &&
          land.Russia->getInfectedNum() == land.Russia->getTotalNum() &&
          land.China->getInfectedNum() == land.China->getTotalNum() &&
          land.NorthAmerica->getInfectedNum() == land.NorthAmerica->getTotalNum() &&
          land.Africa->getInfectedNum() == land.Africa->getTotalNum() &&
          land.GreenLand->getInfectedNum() == land.GreenLand->getTotalNum() &&
          land.Austria->getInfectedNum() == land.Austria->getTotalNum()) {
        ci::gl::drawString("You win the game", vec2(450, 750), ci::Color("blue"));
      }
    }

  }

  void Sketchpad::HandleBrush(const vec2 &brush_screen_coords) {
    //choose the first infected country
    if(!start) {
      if((brush_screen_coords[0] - 240) * (brush_screen_coords[0] - 240) +
          (brush_screen_coords[1] - 240) * (brush_screen_coords[1] - 240) < 900) {
        land.NorthAmerica->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 320) * (brush_screen_coords[0] - 320) +
              (brush_screen_coords[1] - 460) * (brush_screen_coords[1] - 460) < 900) {
        land.SouthAmerica->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 420) * (brush_screen_coords[0] - 420) +
              (brush_screen_coords[1] - 70) * (brush_screen_coords[1] - 70) < 900) {
        land.GreenLand->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 920) * (brush_screen_coords[0] - 920) +
              (brush_screen_coords[1] - 170) * (brush_screen_coords[1] - 170) < 900) {
        land.Russia->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 920) * (brush_screen_coords[0] - 920) +
              (brush_screen_coords[1] - 320) * (brush_screen_coords[1] - 320) < 900) {
        land.China->setInfectedNum(1);
      }
      if((brush_screen_coords[0] - 700) * (brush_screen_coords[0] - 700) +
              (brush_screen_coords[1] - 450) * (brush_screen_coords[1] - 320) < 450) {
        land.Africa->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 700) * (brush_screen_coords[0] - 700) +
              (brush_screen_coords[1] - 280) * (brush_screen_coords[1] - 280) < 450) {
        land.Europe->setInfectedNum(1);
      }
      else if((brush_screen_coords[0] - 1050) * (brush_screen_coords[0] - 1050) +
              (brush_screen_coords[1] - 515) * (brush_screen_coords[1] - 515) < 450) {
        land.Austria->setInfectedNum(1);
      }
      start = true;
    }

    //buy new characteristics
    if(brush_screen_coords[0] > 950 && brush_screen_coords[0] < 1000
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(1);
      land.addCharacteristics(1, person);
    }
    else if(brush_screen_coords[0] > 1000 && brush_screen_coords[0] < 1050
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(2);
      land.addCharacteristics(2, person);
    }
    else if(brush_screen_coords[0] > 1050 && brush_screen_coords[0] < 1100
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(3);
      land.addCharacteristics(3, person);
    }
    else if(brush_screen_coords[0] > 1100 && brush_screen_coords[0] < 1150
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(4);
      land.addCharacteristics(4, person);
    }
    else if(brush_screen_coords[0] > 1150 && brush_screen_coords[0] < 1200
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(5);
      land.addCharacteristics(5, person);
    }
    else if(brush_screen_coords[0] > 1250 && brush_screen_coords[0] < 1300
    && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
      person.usePoints(7);
      land.addCharacteristics(7, person);
    }
  }

  void Sketchpad::mouseDown(ci::app::MouseEvent event) {
    this->HandleBrush(event.getPos());
  }

  void Sketchpad::mouseDrag(ci::app::MouseEvent event) {
    this->HandleBrush(event.getPos());
  }

  void Sketchpad::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN: {

      break;
    }

    case ci::app::KeyEvent::KEY_DELETE:

      break;
    }
  }
}// namespace worldmap