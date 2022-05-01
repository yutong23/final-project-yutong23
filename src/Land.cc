#include <random>
#include "Land.h"
#include <iostream>
#include <queue>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <unordered_map>
#include "cinder/ImageIo.h"				//Loading and displaying images
#include "cinder/gl/Texture.h"
#include <string>


namespace worldmap {

using glm::vec2;
using ci::Rand;

Land::Land() {
    NorthAmerica = new country(100000, 0, 37, 5, 5, 9);
    SouthAmerica = new country(10000000, 0, 37, 5, 5, 7);;
    Russia = new country(10000, 0, 17, 2, 1, 7);;
    China = new country(10000000, 0, 37, 5, 5, 7);;
    India = new country(10000000, 0, 37, 5, 5, 7);;
    Austria = new country(10000, 0, 40, 4, 5, 8);;
    Europe = new country(10000000, 0, 37, 3, 5, 8);;
    Africa = new country(1000000, 0, 45, 5, 3, 6);;
    GreenLand = new country(100, 0, 10, 5, 5, 7);;
}

void Land::Americas() const {
  cinder::Path2d mPath;
  mPath.moveTo(vec2(110, 160));
  mPath.curveTo(vec2(115, 140), vec2(120, 140), vec2(135, 140));
  mPath.curveTo(vec2(140, 140), vec2(150, 150), vec2(170, 160));
  mPath.curveTo(vec2(180, 155), vec2(270, 160), vec2(250, 160));
  mPath.curveTo(vec2(260, 135), vec2(310, 120), vec2(300, 125));
  mPath.curveTo(vec2(310, 120), vec2(340, 145), vec2(285, 195));
  mPath.curveTo(vec2(265, 200), vec2(290, 240), vec2(310, 250));
  mPath.curveTo(vec2(320, 150), vec2(340, 200), vec2(335, 195));
  mPath.curveTo(vec2(340, 205), vec2(345, 225), vec2(370, 245));
  mPath.curveTo(vec2(350, 335), vec2(280, 355), vec2(260, 350));
  mPath.curveTo(vec2(250, 350), vec2(240, 385), vec2(250, 390));
  mPath.curveTo(vec2(260, 400), vec2(280, 410), vec2(290, 420));
  mPath.curveTo(vec2(300, 410), vec2(300, 390), vec2(310, 400));
  mPath.curveTo(vec2(310, 410), vec2(390, 440), vec2(400, 450));
  mPath.curveTo(vec2(395, 465), vec2(300, 620), vec2(290, 630));
  mPath.curveTo(vec2(290, 625), vec2(300, 520), vec2(300, 500));
  mPath.curveTo(vec2(280, 490), vec2(270, 440), vec2(290, 430));
  mPath.curveTo(vec2(280, 420), vec2(200, 370), vec2(190, 350));
  mPath.curveTo(vec2(180, 340), vec2(170, 300), vec2(180, 290));
  mPath.curveTo(vec2(170, 280), vec2(170, 235), vec2(155, 220));
  mPath.curveTo(vec2(160, 210), vec2(100, 166), vec2(110, 160));
  ci::gl::draw(mPath);
}

void Land::Eurasia() const {
  cinder::Path2d mPath2;
  mPath2.moveTo(vec2(930, 70));
  mPath2.curveTo(vec2(940, 65), vec2(720, 180), vec2(730, 170));
  mPath2.curveTo(vec2(700, 130), vec2(730, 170), vec2(700, 130));
  mPath2.curveTo(vec2(630, 220), vec2(700, 130), vec2(630, 220));
  mPath2.curveTo(vec2(625, 245), vec2(660, 250), vec2(670, 220));
  mPath2.curveTo(vec2(690, 195), vec2(670, 220), vec2(690, 195));
  mPath2.curveTo(vec2(688, 205), vec2(673, 220), vec2(675, 230));
  mPath2.curveTo(vec2(680, 245), vec2(710, 220), vec2(725, 230));
  mPath2.curveTo(vec2(700, 235), vec2(620, 295), vec2(610, 290));
  mPath2.curveTo(vec2(608, 300), vec2(620, 315), vec2(630, 310));
  mPath2.curveTo(vec2(700, 310), vec2(634, 305), vec2(750, 330));
  mPath2.curveTo(vec2(770, 330), vec2(770, 360), vec2(750, 360));
  mPath2.curveTo(vec2(740, 370), vec2(640, 370), vec2(620, 340));
  mPath2.curveTo(vec2(600, 330), vec2(590, 390), vec2(600, 390));
  mPath2.curveTo(vec2(590, 400), vec2(650, 460), vec2(660, 450));
  mPath2.curveTo(vec2(660, 460), vec2(670, 500), vec2(680, 510));
  mPath2.curveTo(vec2(700, 570), vec2(680, 510), vec2(700, 570));
  mPath2.curveTo(vec2(780, 370), vec2(770, 450), vec2(780, 370));
  mPath2.curveTo(vec2(780, 370), vec2(770, 450), vec2(810, 400));
  mPath2.curveTo(vec2(800, 360), vec2(810, 400), vec2(800, 360));
  mPath2.curveTo(vec2(870, 385), vec2(800, 365), vec2(860, 380));
  mPath2.curveTo(vec2(880, 440), vec2(860, 380), vec2(880, 440));
  mPath2.curveTo(vec2(900, 380), vec2(880, 440), vec2(900, 380));
  mPath2.curveTo(vec2(915, 400), vec2(940, 450), vec2(950, 440));
  mPath2.curveTo(vec2(965, 430), vec2(950, 390), vec2(960, 380));
  mPath2.curveTo(vec2(965, 380), vec2(990, 370), vec2(1000, 340));
  mPath2.curveTo(vec2(1010, 340), vec2(990, 300), vec2(980, 295));
  mPath2.curveTo(vec2(970, 270), vec2(990, 260), vec2(1000, 275));
  mPath2.curveTo(vec2(1010, 280), vec2(1010, 270), vec2(1000, 265));
  mPath2.curveTo(vec2(990, 255), vec2(1010, 235), vec2(1020, 245));
  mPath2.curveTo(vec2(1160, 190), vec2(1020, 245), vec2(1180, 170));
  mPath2.curveTo(vec2(930, 70), vec2(1160, 190), vec2(930, 70));
  ci::gl::draw(mPath2);
}

void Land::Australia() const {
  cinder::Path2d mPath3;
  mPath3.moveTo(vec2(950, 530));
  mPath3.curveTo(vec2(960, 525), vec2(970, 590), vec2(1010, 560));
  mPath3.curveTo(vec2(1040, 530), vec2(1060, 560), vec2(1070, 590));
  mPath3.curveTo(vec2(1080, 620), vec2(1120, 560), vec2(1110, 540));
  mPath3.curveTo(vec2(1060, 470), vec2(1110, 530), vec2(1050, 470));
  mPath3.curveTo(vec2(940, 520), vec2(1040, 460), vec2(950, 530));
  ci::gl::draw(mPath3);
}

void Land::Greenland() const {
  cinder::Path2d mPath4;
  mPath4.moveTo(vec2(350, 30));
  mPath4.curveTo(vec2(440, 190), vec2(360, 40), vec2(430, 200));
  mPath4.curveTo(vec2(500, 30), vec2(430, 200), vec2(500, 30));
  ci::gl::draw(mPath4); // 450 50
}

// display the map
 void Land::Display(int command, player person) const {
  ci::Color background_color("white");
  ci::gl::clear(background_color);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(ci::Rectf(vec2(kTopLeftX, kTopLeftY), vec2(kTopLeftX + 1100, kTopLeftY + 620)));

  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(950,700),
                vec2(1000,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1000,700),
                vec2(1050,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1050,700),
                vec2(1100,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1100,700),
                vec2(1150,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1150,700),
                vec2(1200,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1200,700),
                vec2(1250,750)));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(1250,700),
                vec2(1300,750)));

  ci::gl::drawString("Total Points: " + to_string(person.getPoints()), vec2(1100, 770),
                     ci::Color("blue"));

  ci::gl::drawString("NorthAmerica Total People: " + to_string(100000) + ", Infected People: " + to_string(NorthAmerica->getInfectedNum()), vec2(50, 670),
                     ci::Color("blue"));

  ci::gl::drawString("SouthAmerica Total People: " + to_string(100000) + ", Infected People: " + to_string(SouthAmerica->getInfectedNum()), vec2(50, 690),
                     ci::Color("blue"));

  ci::gl::drawString("Russia Total People: " + to_string(1000000) + ", Infected People: " + to_string(Russia->getInfectedNum()), vec2(50, 710),
                     ci::Color("blue"));

  ci::gl::drawString("China Total People: " + to_string(300000) + ", Infected People: " + to_string(China->getInfectedNum()), vec2(50, 730),
                     ci::Color("blue"));

  ci::gl::drawString("India Total People: " + to_string(600000) + ", Infected People: " + to_string(India->getInfectedNum()), vec2(50, 750),
                     ci::Color("blue"));

  ci::gl::drawString("Austria Total People: " + to_string(20000) + ", Infected People: " + to_string(Austria->getInfectedNum()), vec2(350, 670),
                     ci::Color("blue"));

  ci::gl::drawString("Europe Total People: " + to_string(400000) + ", Infected People: " + to_string(Europe->getInfectedNum()), vec2(350, 690),
                     ci::Color("blue"));

  ci::gl::drawString("Africa Total People: " + to_string(300000) + ", Infected People: " + to_string(Africa->getInfectedNum()), vec2(350, 710),
                     ci::Color("blue"));

  ci::gl::drawString("GreenLand Total People: " + to_string(800) + ", Infected People: " + to_string(GreenLand->getInfectedNum()), vec2(350, 730),
                     ci::Color("blue"));
  std::unordered_map<float, float> bound;
  ci::gl::color(ci::Color("black"));
  Americas();
  Eurasia();
  Australia();
  Greenland();

  }


}