#ifndef _INITIALIZER_FOLLOW_H_
#define _INITIALIZER_FOLLOW_H_

#include "../events.h"

int initialize_follow(struct Event *event,
                      struct Model *model,
                      struct MT19937 *gen,
                      char *timestamp);

#endif
