#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "Land.h"
#include "player.h"
// using worldmap::Land;

namespace worldmap{

/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse events.
 */
class Sketchpad: public ci::app::App{
public:
  /**
   * Creates a sketchpad.
   */
  Sketchpad();

  /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
  void draw() override;

  /**
   * Player chooses to change virus attributes
   *
   * @param brush_screen_coords the screen coordinates at which the brush is
   *           located
   */
  void HandleBrush(const glm::vec2 &brush_screen_coords);


  void Clear();

  void mouseDown(ci::app::MouseEvent event) override;

  void mouseDrag(ci::app::MouseEvent event) override;

  void keyDown(ci::app::KeyEvent event) override;


private:
  glm::vec2 top_left_corner_ = glm::vec2(100,100);
  Land land;
  player person;
  const int kWindowSizeX = 1300;
  const int kWindowSizeY = 800;
  int command = 0;

};

}// namespace worldmap