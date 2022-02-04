#ifndef _INITIALIZER_UNFOLLOW_H_
#define _INITIALIZER_UNFOLLOW_H_

#include "../events.h"

int initialize_unfollow(struct Event *event,
                        struct Model *model,
                        struct MT19937 *gen,
                        char *timestamp);

#endif
