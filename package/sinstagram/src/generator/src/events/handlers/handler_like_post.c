#include "handler_like_post.h"

int handle_like_post(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_posts || !model->cnt_active_user) {
        return 2;
    }
    ++(model->cnt_likes);
    model->post_likes[event->data.like_post.post_id * 10000 +
                      event->data.like_post.user_id] = 1;
    fprintf(fout,
            "\"%u\",\"%u\",\"%u\",\"%s\"\n",
            event->type,
            event->data.like_post.post_id + 1,
            event->data.like_post.user_id + 1,
            event->data.like_post.time_liked);
    return 0;
}
