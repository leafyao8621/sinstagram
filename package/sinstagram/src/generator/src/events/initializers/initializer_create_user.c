#include <string.h>
#include "initializer_create_user.h"

int initialize_create_user(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model) {
        return 1;
    }
    generator_generate_string(gen, event->data.create_user.name, 50);
    generator_generate_dob(gen, event->data.create_user.dob);
    strcpy(event->data.create_user.created, timestamp);
    return 0;
}
