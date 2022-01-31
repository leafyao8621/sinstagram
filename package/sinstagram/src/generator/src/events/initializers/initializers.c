#include "initializers.h"
#include "initializer_create_user.h"
#include "initializer_remove_user.h"
#include "initializer_update_user.h"

int (*initializers[11])(struct Event *event,
                        struct Model *model,
                        struct MT19937 *gen,
                        char *timestamp) = {
    initialize_create_user,
    initialize_remove_user,
    initialize_update_user,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
