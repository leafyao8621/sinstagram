#include "handler_like_post.h"

int handle_unlike_post(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_posts ||
        !model->cnt_active_user ||
        !model->cnt_likes) {
        return 2;
    }
    --(model->cnt_likes);
    model->post_likes[event->data.unlike_post.post_id * 10000 +
                      event->data.unlike_post.user_id] = 0;
    fprintf(fout,
            "\"%u\",\"%u\",\"%u\"\n",
            event->type,
            event->data.unlike_post.post_id + 1,
            event->data.unlike_post.user_id + 1);
    return 0;
}
