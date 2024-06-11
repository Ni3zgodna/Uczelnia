#include "timer.h"

double Timer::get_elapsed_seconds() noexcept
{
    time_point end_time = clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    return duration.count();
}
