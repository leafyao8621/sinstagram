#ifndef _INITIALIZER_CREATE_POST_H_
#define _INITIALIZER_CREATE_POST_H_

#include "../events.h"

int initialize_create_post(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp);

#endif
