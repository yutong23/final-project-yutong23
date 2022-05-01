//
// Created by Yutong Li on 2022/4/21.
//
#include "cinder/app/Event.h"
#include "player.h"
#include <termios.h>
#include <iostream>
namespace worldmap {

player::player() {
  this->points = 1000000;
  characteristic["Improve the cold resistance of viruses"] = 10;
  characteristic["Improve the heat resistance of viruses"] = 10;
  characteristic["Improve the ability of the virus to spread in cities"] = 10;
  characteristic["Have cough symptoms"] = 5;
  characteristic["Have fever symptoms"] = 5;
  characteristic["Having trouble breathing"] = 10;
  characteristic["Have dizziness symptoms"] = 5;
}

int player::getPoints() {
  return points;
}

void player::addPoints(int addNum) {
  this->points += addNum;

}

void player::usePoints(int command) {
  if(command == 1){
    this->points = this->points - characteristic.find("Improve the cold resistance of viruses")->second;
  }
  else if(command == 2){
    this->points = this->points - characteristic.find("Improve the heat resistance of viruses")->second;
  }
  else if(command == 3){
    this->points = this->points - characteristic.find("Improve the ability of the virus to spread in cities")->second;
  }
  else if(command == 4){
    this->points = this->points - characteristic.find("Have cough symptoms")->second;
  }
  else if(command == 5){
    this->points = this->points - characteristic.find("Have fever symptoms")->second;
  }
  else if(command == 6){
    this->points = this->points - characteristic.find("Having trouble breathing")->second;
  }
  else if(command == 7){
    this->points = this->points - characteristic.find("Have dizziness symptoms")->second;
  }
  updateCharacteristicPoints();
}

void player::updateCharacteristicPoints() {
  for(auto a : characteristic) {
    a.second = a.second + 5;
  }
}



}
