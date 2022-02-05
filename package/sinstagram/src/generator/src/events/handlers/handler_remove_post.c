#include "handler_remove_post.h"

int handle_remove_post(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_posts) {
        return 2;
    }
    --(model->cnt_active_posts);
    model->posts[event->data.remove_post.id] = 0;
    fprintf(fout,
            "\"%u\",\"%u\"\n",
            event->type,
            event->data.remove_post.id + 1);
    return 0;
}
