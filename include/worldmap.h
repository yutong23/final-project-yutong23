#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Land.h"

namespace worldmap {

/**
 * An app for visualizing the behavior of the worldmap
 */
class WorldMap : public ci::app::App {
 public:
  WorldMap();

  void draw() override;
  void update() override;

  const int kWindowSizeX = 1300;
  const int kWindowSizeY = 800;
  const size_t kWidth = 1000;
  const size_t kHeight = 600;

};

}  // namespace idealgas
