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

  /**
   * get the total point of player
   */
  int getPoints();

  /**
   * add some points to player
   */
  void addPoints(int addNum);

  /**
   * use some points
   */
  void usePoints(int command);

  /**
   * update the needed points for new characteristic
   */
  void updateCharacteristicPoints();

  unordered_map<string, int> characteristic;

private:
  int points;
};
}

#endif // IDEAL_GAS_PLAYER_H
