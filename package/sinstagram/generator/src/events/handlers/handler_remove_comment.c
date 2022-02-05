#include "handler_remove_comment.h"

int handle_remove_comment(struct Event *event,
                          struct Model *model,
                          FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_post_comments) {
        return 2;
    }
    --(model->cnt_active_post_comments);
    model->post_comments[event->data.remove_comment.id] = 0;
    fprintf(fout,
            "\"%u\",\"%u\"\n",
            event->type,
            event->data.remove_comment.id + 1);
    return 0;
}
