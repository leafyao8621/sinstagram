#include <string.h>
#include "initializer_unlike_post.h"

int initialize_unlike_post(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_posts ||
        !model->cnt_active_user ||
        !model->cnt_likes) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unlike_post.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.unlike_post.post_id);
         !model->users[event->data.unlike_post.user_id] ||
         !model->posts[event->data.unlike_post.post_id] ||
         !model->post_likes[event->data.unlike_post.post_id * 10000 +
                            event->data.unlike_post.user_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.unlike_post.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.unlike_post.post_id));
    return 0;
}
