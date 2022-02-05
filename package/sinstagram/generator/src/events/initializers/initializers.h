#ifndef _INITIALIZERS_H_
#define _INITIALIZERS_H_

#include "../events.h"

extern int (*initializers[11])(struct Event *event,
                               struct Model *model,
                               struct MT19937 *gen,
                               char *timestamp);

#endif
