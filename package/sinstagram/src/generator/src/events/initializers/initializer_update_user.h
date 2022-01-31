#ifndef _INITIALIZER_UPDATE_USER_
#define _INITIALIZER_UPDATE_USER_

#include "../events.h"

int initialize_update_user(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp);

#endif
