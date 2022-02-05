#include "initializer_remove_post.h"

int initialize_remove_post(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_posts) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.remove_post.id);
         !model->posts[event->data.remove_post.id];
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.remove_post.id));
    return 0;
}
