#include "initializer_remove_user.h"

int initialize_remove_user(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !gen || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_user) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.remove_user.id);
         !model->users[event->data.remove_user.id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.remove_user.id));
    return 0;
}
