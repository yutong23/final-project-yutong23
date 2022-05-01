#include "sketchpad.h"
namespace worldmap {

using glm::vec2;

Sketchpad::Sketchpad()
{
  ci::app::setWindowSize(kWindowSizeX, kWindowSizeY);
}

void Sketchpad::draw()  {
  land.Display(command, person);
}

void Sketchpad::HandleBrush(const vec2 &brush_screen_coords) {
  std::cout<<brush_screen_coords[0]<<std::endl;
  std::cout<<brush_screen_coords[1]<<std::endl;
  if(brush_screen_coords[0] > 950 && brush_screen_coords[0] < 1000
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(1);
  }
  else if(brush_screen_coords[0] > 950 && brush_screen_coords[0] < 1000
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(2);
  }
  else if(brush_screen_coords[0] > 1000 && brush_screen_coords[0] < 1050
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(3);
  }
  else if(brush_screen_coords[0] > 1050 && brush_screen_coords[0] < 1100
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(4);
  }
  else if(brush_screen_coords[0] > 1100 && brush_screen_coords[0] < 1150
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(5);
  }
  else if(brush_screen_coords[0] > 1200 && brush_screen_coords[0] < 1250
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(6);
  }
  else if(brush_screen_coords[0] > 1250 && brush_screen_coords[0] < 1300
  && brush_screen_coords[1] > 700 && brush_screen_coords[1] < 750) {
    person.usePoints(7);
  }

}

void Sketchpad::Clear() {

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
//    sketchpad_.Clear();

    break;
  }
}


}// namespace worldmap