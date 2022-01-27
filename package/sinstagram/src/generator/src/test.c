#include <time.h>
#include "simulator/simulator.h"

struct Simulator simulator;

int main(void) {
    simulator_initialize(&simulator, time(NULL) - 31536000, 1000, "dump");
    simulator_run(&simulator, 10, 1);
    return 0;
}
