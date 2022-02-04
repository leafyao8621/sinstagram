#include <string.h>
#include "initializer_unfollow.h"

int initialize_unfollow(struct Event *event,
                        struct Model *model,
                        struct MT19937 *gen,
                        char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_followings) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unfollow.from_id),
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unfollow.to_id);
         !model->users[event->data.unfollow.from_id] ||
         !model->users[event->data.unfollow.to_id] ||
         event->data.unfollow.to_id == event->data.unfollow.from_id ||
         !model->following[event->data.unfollow.from_id * 10000 +
                           event->data.unfollow.to_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unfollow.from_id),
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unfollow.to_id));
    return 0;
}
