#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include <time.h>

#include "../model/model.h"
#include "../events/events.h"
#include "../util/generator.h"

struct Simulator {
    time_t time_now;
    struct Event event;
    struct Model model;
    struct MT19937 gen;
    const char *dir;
};

int simulator_initialize(struct Simulator *simulator,
                         time_t start_time,
                         unsigned seed,
                         const char *dir);

#endif
