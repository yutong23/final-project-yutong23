//
// Created by Yutong Li on 2022/4/21.
//

#ifndef IDEAL_GAS_PLAYER_H
#define IDEAL_GAS_PLAYER_H
#include <string>
#include <unordered_map>
using namespace std;
namespace worldmap{
class player {
public:
  player();

  int getPoints();

  void addPoints(int addNum);

  void usePoints(int command);

  void updateCharacteristicPoints();

  unordered_map<string, int> characteristic;

private:
  int points;
};

}

#endif // IDEAL_GAS_PLAYER_H
