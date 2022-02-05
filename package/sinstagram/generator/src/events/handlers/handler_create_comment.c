#include "handler_create_comment.h"

int handle_create_comment(struct Event *event,
                          struct Model *model,
                          FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (model->cnt_post_comments >= 1000000) {
        return 2;
    }
    ++(model->cnt_post_comments);
    ++(model->cnt_active_post_comments);
    *(model->post_comments_end++) = 1;
    fprintf(fout,
            "\"%u\",\"%u\",\"%u\",\"%s\","
            "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
            event->type,
            event->data.create_comment.post_id + 1,
            event->data.create_comment.user_id + 1,
            event->data.create_comment.textual_content,
            event->data.create_comment.time_commented,
            event->data.create_comment.url[0],
            event->data.create_comment.url[1],
            event->data.create_comment.url[2],
            event->data.create_comment.url[3],
            event->data.create_comment.url[4]);
    return 0;
}
