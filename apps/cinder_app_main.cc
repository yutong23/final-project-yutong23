#include "sketchpad.h"

using worldmap::Sketchpad;
void prepareSettings(Sketchpad::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(Sketchpad, ci::app::RendererGl, prepareSettings);


