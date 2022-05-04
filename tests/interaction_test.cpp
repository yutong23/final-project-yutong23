#include <iostream>
#include "Land.h"
#include "player.h"
#include "sketchpad.h"
#include <catch2/catch.hpp>
#include <fstream>

namespace worldmap {

TEST_CASE("Test Points Using") {
  player person;
  person.usePoints(1);
  REQUIRE(person.getPoints() == 999990);
  person.usePoints(2);
  REQUIRE(person.getPoints() == 999980);
  person.usePoints(3);
  REQUIRE(person.getPoints() == 999970);
  person.usePoints(4);
  REQUIRE(person.getPoints() == 999965);
  person.usePoints(5);
  REQUIRE(person.getPoints() == 999960);
}

TEST_CASE("Test Update Characteristics") {
  player person;
  person.updateCharacteristicPoints();
  REQUIRE(person.characteristic["Improve the cold resistance of viruses"] == 10);
  REQUIRE(person.characteristic["Have cough symptoms"] == 5);
  REQUIRE(person.characteristic["Improve the heat resistance of viruses"] == 10);
  REQUIRE(person.characteristic["Improve the ability of the virus to spread in cities"] == 10);
  REQUIRE(person.characteristic["Have fever symptoms"] == 5);
  REQUIRE(person.characteristic["Having trouble breathing"] == 10);
  REQUIRE(person.characteristic["Have dizziness symptoms"] == 5);
}

TEST_CASE("Test Add Points") {
  player person;
  person.addPoints(10);
  REQUIRE(person.getPoints() == 1000010);
  person.addPoints(100);
  REQUIRE(person.getPoints() == 1000110);
  person.addPoints(50);
  REQUIRE(person.getPoints() == 1000160);
  person.addPoints(60);
  REQUIRE(person.getPoints() == 1000220);
}

TEST_CASE("Test neighbor connection") {
  Land land;
  land.setConnection();
  REQUIRE(land.NorthAmerica->neighboringCountries[0] == land.SouthAmerica);
  REQUIRE(land.SouthAmerica->neighboringCountries[0] == land.NorthAmerica);
  REQUIRE(land.Europe->neighboringCountries[0] == land.China);
  REQUIRE(land.China->neighboringCountries[0] == land.Europe);
  REQUIRE(land.China->neighboringCountries[1] == land.Russia);
  REQUIRE(land.Russia->neighboringCountries[1] == land.China);
  REQUIRE(land.Russia->neighboringCountries[1] == land.Europe);
  REQUIRE(land.Europe->neighboringCountries[1] == land.Russia);
}

TEST_CASE("Test neighbor connection") {
  Land land;
  land.setConnection();
  REQUIRE(land.China->airlineToCountry[0] == land.NorthAmerica);
  REQUIRE(land.NorthAmerica->airlineToCountry[0] == land.China);
  REQUIRE(land.Europe->airlineToCountry[0] == land.NorthAmerica);
  REQUIRE(land.NorthAmerica->airlineToCountry[0] == land.Europe);
  REQUIRE(land.Europe->airlineToCountry[0] == land.SouthAmerica);
  REQUIRE(land.SouthAmerica->airlineToCountry[0] == land.Europe);
  REQUIRE(land.Russia->airlineToCountry[0] == land.GreenLand);
  REQUIRE(land.GreenLand->airlineToCountry[0] == land.Russia);
  REQUIRE(land.Austria->airlineToCountry[0] == land.SouthAmerica);
  REQUIRE(land.SouthAmerica->airlineToCountry[0] == land.Austria);
  REQUIRE(land.Africa->airlineToCountry[0] == land.Europe);
  REQUIRE(land.Europe->airlineToCountry[0] == land.Africa);
}

TEST_CASE("Test timer clock") {
  TimerClock timer;
  REQUIRE(timer.getTimerSecond() == timer.getTimerMicroSec() * 1000);
}
}// namespace naivebayes