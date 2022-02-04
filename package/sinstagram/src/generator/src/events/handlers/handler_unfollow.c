#include "handler_unfollow.h"

int handle_unfollow(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_followings) {
        return 2;
    }
    --(model->cnt_followings);
    model->following[event->data.unfollow.from_id * 10000 +
                     event->data.unfollow.to_id] = 0;
    fprintf(fout,
            "\"%u\",\"%u\",\"%u\"\n",
            event->type,
            event->data.unfollow.from_id + 1,
            event->data.unfollow.to_id + 1);
    return 0;
}
