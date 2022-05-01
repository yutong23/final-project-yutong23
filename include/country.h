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
  country(int totalNum, int infectedNum, int countryTemperature, int airportNum, int pierNum, double countryDevelopment);

  country(int totalNum, int infectedNum, int countryTemperature, int airportNum,
          int pierNum, int countryDevelopment);
  void infectedUpdate();

  void checkNeighboringCountrie();

  void checkAirlineToCountrie();

  void checkShipToCountrie();

  bool getInfection();

  bool getTotalNum();

  bool getInfectedNum();

private:
  int totalNum;
  int infectedNum;
  int countryTemperature;
  int airportNum;
  int pierNum;
  float countryDevelopment;
  bool fullInfection;
  std::vector<country> neighboringCountries;
  std::vector<country> airlineToCountry;
  std::vector<country> shipToCountry;
};

}


#endif // IDEAL_GAS_COUNTRY_H
