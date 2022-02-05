#include "handler_create_post.h"

int handle_create_post(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (model->cnt_posts >= 1000000) {
        return 2;
    }
    ++model->cnt_posts;
    ++model->cnt_active_posts;
    *(model->posts_end++) = 1;
    fprintf(fout,
            "\"%u\",\"%u\",\"%s\","
            "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
            event->type,
            event->data.create_post.user_id + 1,
            event->data.create_post.textual_content,
            event->data.create_post.time_posted,
            event->data.create_post.url[0],
            event->data.create_post.url[1],
            event->data.create_post.url[2],
            event->data.create_post.url[3],
            event->data.create_post.url[4]);
    return 0;
}
