#include <string.h>
#include "initializer_create_user.h"

int initialize_create_user(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (model->cnt_user == 10000) {
        return 2;
    }
    generator_generate_string(gen, event->data.create_user.name, 50);
    generator_generate_enum(gen, 2, &event->data.create_user.sex);
    generator_generate_enum(gen, 3, &event->data.create_user.gender);
    generator_generate_enum(gen, 10, &event->data.create_user.education_level);
    generator_generate_dob(gen, event->data.create_user.dob);
    strcpy(event->data.create_user.created, timestamp);
    return 0;
}
