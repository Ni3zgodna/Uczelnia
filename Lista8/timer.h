#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
    using clock = std::chrono::steady_clock;
    using time_point = clock::time_point;

  public:
    Timer() noexcept { start(); };

    void start() noexcept { start_time = clock::now(); };

    double get_elapsed_seconds() noexcept;
    double get_elapsed_milli_seconds() noexcept { return 1000.0 * get_elapsed_seconds(); }

  private:
    time_point start_time;
};

#endif // TIMER_H
