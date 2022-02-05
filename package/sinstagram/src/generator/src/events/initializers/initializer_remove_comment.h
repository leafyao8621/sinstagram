#ifndef _INITIALIZER_REMOVE_COMMENT_H_
#define _INITIALIZER_REMOVE_COMMENT_H_

#include "../events.h"

int initialize_remove_comment(struct Event *event,
                              struct Model *model,
                              struct MT19937 *gen,
                              char *timestamp);

#endif
