#ifndef _TimerClock_hpp_
#define _TimerClock_hpp_

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace worldmap {

class TimerClock {
public:
  TimerClock() { update(); }

  ~TimerClock() {}

  void update() { _start = high_resolution_clock::now(); }

  double getTimerSecond() { return getTimerMicroSec() * 0.000001; }

  double getTimerMilliSec() { return getTimerMicroSec() * 0.001; }

  long long getTimerMicroSec() {
    return duration_cast<microseconds>(high_resolution_clock::now() - _start)
        .count();
  }

private:
  time_point<high_resolution_clock> _start;
};

}

#endif
