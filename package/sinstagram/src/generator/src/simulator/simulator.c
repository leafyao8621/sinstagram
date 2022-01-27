#include "simulator.h"

int simulator_initialize(struct Simulator *simulator,
                         time_t start_time,
                         unsigned seed,
                         const char *dir) {
    if (!simulator || !dir) {
        return 1;
    }
    simulator->time_now = start_time;
    mt19937_initialize(&simulator->gen, seed);
    model_initialize(&simulator->model);
    simulator->dir = dir;
    return 0;
}
