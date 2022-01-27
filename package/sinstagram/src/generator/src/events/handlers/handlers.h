#ifndef _HANDLERS_H_
#define _HANDLERS_H_

#include "../events.h"

extern int (*handlers[11])(struct Event *event,
                           struct Model *model,
                           FILE *fout);

#endif
