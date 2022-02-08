#include <string.h>
#include "initializer_create_comment.h"

int initialize_create_comment(struct Event *event,
                              struct Model *model,
                              struct MT19937 *gen,
                              char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_posts ||
        !model->cnt_active_user ||
        model->cnt_post_comments >= 1000000) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.create_comment.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.create_comment.post_id);
         !model->users[event->data.create_comment.user_id] ||
         !model->posts[event->data.create_comment.post_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.create_comment.user_id),
         generator_generate_idx(gen,
                                model->cnt_posts,
                                &event->data.create_comment.post_id));
    generator_generate_string(gen,
                              event->data.create_comment.textual_content,
                              900);
    unsigned ub = 0;
    generator_generate_idx(gen, 5, &ub);
    for (unsigned i = 0; i < 5; ++i) {
        if (i <= ub) {
            generator_generate_string(gen,
                                      event->data.create_comment.url[i],
                                      900);
        } else {
            *event->data.create_comment.url[i] = 0;
        }
    }
    strcpy(event->data.create_comment.time_commented, timestamp);
    return 0;
}
