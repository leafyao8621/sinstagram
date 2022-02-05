#include "initializer_update_user.h"

int initialize_update_user(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_user) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.update_user.id);
         !model->users[event->data.update_user.id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.update_user.id));
    generator_generate_string(gen, event->data.update_user.name, 50);
    generator_generate_enum(gen, 2, &event->data.update_user.sex);
    generator_generate_enum(gen, 3, &event->data.update_user.gender);
    generator_generate_enum(gen, 10, &event->data.update_user.education_level);
    generator_generate_dob(gen, event->data.update_user.dob);
    return 0;
}
