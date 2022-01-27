#include "initializers.h"
#include "initializer_create_user.h"

int (*initializers[11])(struct Event *event,
                        struct Model *model,
                        struct MT19937 *gen,
                        char *timestamp) = {
    initialize_create_user,
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
