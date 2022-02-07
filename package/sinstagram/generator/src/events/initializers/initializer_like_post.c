#include <string.h>
#include "initializer_like_post.h"

int initialize_like_post(struct Event *event,
                         struct Model *model,
                         struct MT19937 *gen,
                         char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_posts || !model->cnt_active_user) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.like_post.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.like_post.post_id);
         !model->users[event->data.like_post.user_id] ||
         !model->posts[event->data.like_post.post_id] ||
         model->post_likes[event->data.like_post.post_id * 10000 +
                           event->data.like_post.user_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.like_post.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.like_post.post_id));
    strcpy(event->data.like_post.time_liked, timestamp);
    return 0;
}
