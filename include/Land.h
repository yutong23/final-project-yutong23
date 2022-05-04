#pragma once

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "country.h"
#include <math.h>
#include "player.h"

using glm::vec2;

namespace worldmap {

class Land {
public:

   /*
    * Constructor of the land
    */
  Land();

  void setConnection();

  void Display(int command, player person, bool start) const;

  /*
    * Americas land
   */
  void Americas() const;

  /*
    * Eurasia land
   */
  void Eurasia() const;

  /*
    * Australia land
   */
  void Australia() const;

  /*
    * Greenland land
   */
  void Greenland() const;

  void AdvanceOneFrame();

  void addPoint(player person) const;

  void addCharacteristics(int index, player person);
  const size_t kTopLeftX = 100;
  const size_t kTopLeftY = 30;
  const size_t kDefaultWidth = 2000;
  const size_t kDefaultHeight = 2000;
  const size_t kParticleRadii = 5;

  country* NorthAmerica;
  country* SouthAmerica;
  country* Russia;
  country* China;
  country* Austria;
  country* Europe;
  country* Africa;
  country* GreenLand;
 private:
   bool haveAdded = false;
  size_t width_;
  size_t height_;
};

}  // namespace worldmap
