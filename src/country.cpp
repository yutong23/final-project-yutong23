//
// Created by Yutong Li on 2022/4/21.
//

#include "country.h"
#include <iostream>
#include <math.h>
namespace worldmap {
  country::country(int totalNum, int infectedNum, int countryTemperature, int airportNum, int pierNum, int countryDevelopment) {
    this->totalNum = totalNum;
    this->countryTemperature = countryTemperature;
    this->airportNum = airportNum;
    this->pierNum = pierNum;
    this->countryDevelopment = countryDevelopment;
    this->infectedNum = infectedNum;
    this->fullInfection = false;
  }

  void country::infectedUpdate() {
    float infectedFactor = 1;
    infectedFactor = 0.001 + contagious*0.00002 - (abs(countryTemperature - 37)*0.0008 > 0.008 ? 0.008 : abs(countryTemperature - 37)*0.0008)
        + (countryDevelopment < 10 ? 0.002 : 0);
    std::cout<<infectedFactor<<std::endl;
    this->infectedNum = this->infectedNum * (1 + infectedFactor);
    checkNeighboringCountrie();
    checkAirlineToCountrie();
    if(this->totalNum >= this->infectedNum) {
      this->fullInfection = true;
    }
    if(this->infectedNum > this->totalNum) {
      this->infectedNum = this->totalNum;
    }
  }

  void country::checkNeighboringCountrie() {
    for(country* c : neighboringCountries) {
      if(c->getInfectedNum() > 1) {
        srand((unsigned)time(NULL));
        for(int i = 0; i < sqrt(c->getInfectedNum()); i++) {
          int randomNum = (rand() % (100000-1+1)) + 1;
          if(randomNum == 50000) {
            this->infectedNum++;
          }
        }
      }
    }
  }

  void country::checkAirlineToCountrie() {
    for(country* c : airlineToCountry) {
      if(c->getInfection()) {
        srand((unsigned)time(NULL));
        for(int i = 0; i < sqrt(c->getInfectedNum()); i++) {
          int randomNum = (rand() % (500000-1+1)) + 1;
          if(randomNum == 5000) {
            this->infectedNum++;
          }
        }
      }
    }
  }

  bool country::getInfection() {
    return infectedNum > 0;
  }

  bool country::getTotalNum() {
    return totalNum;
  }

  int country::getInfectedNum() {
    return this->infectedNum;
  }

  void country::setInfectedNum(int num) {
    this->infectedNum = num;
  }

}