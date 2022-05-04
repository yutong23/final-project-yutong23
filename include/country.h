//
// Created by Yutong Li on 2022/4/21.
//

#ifndef IDEAL_GAS_COUNTRY_H
#define IDEAL_GAS_COUNTRY_H
#include <math.h>
#include <vector>

namespace worldmap {
class country {
public:

  country(int totalNum, int infectedNum, int countryTemperature, int airportNum,
          int pierNum, int countryDevelopment);

  /**
   * Update the infection satuation
   */
  void infectedUpdate();

  /**
   * Check the neighboring countrie situation
   */
  void checkNeighboringCountrie();

  /**
   * Check the airline countrie situation
   */
  void checkAirlineToCountrie();

  /**
   * Check if the country is infected
   */
  bool getInfection();

  /**
   * return the total number of  people
   */
  bool getTotalNum();

  /**
   * return the total number of infected people
   */
  int getInfectedNum();

  /**
   * Set the total number of infected people
   */
  void setInfectedNum(int num);

  std::vector<country*> neighboringCountries;
  std::vector<country*> airlineToCountry;
  int countryTemperature;
  float countryDevelopment;
  int contagious;
  bool producePoint = false;

private:
  int totalNum;
  float infectedNum;
  int airportNum;
  int pierNum;
  bool fullInfection;
};
}


#endif // IDEAL_GAS_COUNTRY_H
