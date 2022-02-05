#include "initializer_remove_comment.h"

int initialize_remove_comment(struct Event *event,
                              struct Model *model,
                              struct MT19937 *gen,
                              char *timestamp) {
    if (!event || !model || !timestamp) {
        return 1;
    }
    if (!model->cnt_active_post_comments) {
        return 2;
    }
    for (generator_generate_idx(gen,
                                model->cnt_post_comments,
                                &event->data.remove_comment.id);
         !model->post_comments[event->data.remove_comment.id];
         generator_generate_idx(gen,
                                model->cnt_post_comments,
                                &event->data.remove_comment.id));
    return 0;
}
