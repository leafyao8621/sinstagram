#include <string.h>
#include "initializer_follow.h"

int initialize_follow(struct Event *event,
                      struct Model *model,
                      struct MT19937 *gen,
                      char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (model->cnt_active_user < 2) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.follow.from_id);
         !model->users[event->data.follow.from_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.follow.from_id));
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.follow.to_id);
         !model->users[event->data.follow.to_id] ||
         event->data.follow.to_id == event->data.follow.from_id ||
         model->following[event->data.follow.from_id * 10000 +
                          event->data.follow.to_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.follow.to_id));
    strcpy(event->data.follow.time_initiated, timestamp);
    return 0;
}
