#include <string.h>
#include "initializer_create_post.h"

int initialize_create_post(struct Event *event,
                           struct Model *model,
                           struct MT19937 *gen,
                           char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_user || model->cnt_posts >= 1000000) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.create_post.user_id);
         !model->users[event->data.create_post.user_id];
         generator_generate_idx(gen,
                                model->cnt_user,
                                &event->data.create_post.user_id));
    generator_generate_string(gen,
                              event->data.create_post.textual_content,
                              1000);
    int ub = 0;
    generator_generate_idx(gen, 5, &ub);
    char **iter = event->data.create_post.url;
    for (int i = 0; i < 5; ++i, ++iter) {
        if (i <= ub) {
            generator_generate_string(gen, *iter, 1000);
        } else {
            **iter = 0;
        }
    }
    strcpy(event->data.create_post.time_posted, timestamp);
    return 0;
}
