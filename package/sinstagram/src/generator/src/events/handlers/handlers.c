#include "handlers.h"
#include "handler_create_user.h"

int (*handlers[11])(struct Event *event,
                    struct Model *model,
                    FILE *fout) = {
    handle_create_user,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
