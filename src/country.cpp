//
// Created by Yutong Li on 2022/4/21.
//

#include "country.h"
#include <iostream>
namespace worldmap {
  country::country(int totalNum, int infectedNum, int countryTemperature, int airportNum, int pierNum, int countryDevelopment) {
    this->totalNum = totalNum;
    this->countryTemperature = countryTemperature;
    this->airportNum = airportNum;
    this->pierNum = pierNum;
    this->countryDevelopment = countryDevelopment;
    this->infectedNum = infectedNum;
    this->fullInfection = false;
//    infectedUpdate();

  }

  void country::infectedUpdate() {
    float infectedFactor = 1;
    infectedFactor = (1 + 5*(1/abs(countryTemperature - 37))) * (1 + 0.1*airportNum + 0.1*pierNum)
                     * (1/countryDevelopment);
    this->infectedNum = this->infectedNum * infectedFactor;
    checkNeighboringCountrie();
    checkAirlineToCountrie();
    checkShipToCountrie();
    if(this->totalNum >= this->infectedNum) {
      this->fullInfection = true;
    }
  }

  void country::checkNeighboringCountrie() {
    for(country c : neighboringCountries) {
      if(c.getInfection()) {
        srand((unsigned)time(NULL));
        for(int i = 0; i < c.getInfectedNum(); i++) {
          int randomNum = (rand() % (10000-1+1)) + 1;
          if(randomNum == 5000) {
            this->infectedNum++;
          }
        }
      }
    }
  }

  void country::checkAirlineToCountrie() {
    for(country c : airlineToCountry) {
      if(c.getInfection()) {
        srand((unsigned)time(NULL));
        for(int i = 0; i < c.getInfectedNum(); i++) {
          int randomNum = (rand() % (10000-1+1)) + 1;
          if(randomNum == 5000) {
            this->infectedNum++;
          }
        }
      }
    }
  }

  void country::checkShipToCountrie() {
    for(country c : shipToCountry) {
      if(c.getInfection()) {
        srand((unsigned)time(NULL));
        for(int i = 0; i < c.getInfectedNum(); i++) {
          int randomNum = (rand() % (10000-1+1)) + 1;
          if(randomNum == 5000) {
            this->infectedNum++;
          }
        }
      }
    }
  }

  bool country::getInfection() {
    return infectedNum > 0;
  };

  bool country::getTotalNum() {
    return totalNum;
  };

  bool country::getInfectedNum() {
    return infectedNum;
  };

}