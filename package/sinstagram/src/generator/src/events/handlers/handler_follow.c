#include "handler_follow.h"

int handle_follow(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (model->cnt_active_user < 2) {
        return 2;
    }
    ++(model->cnt_followings);
    model->following[event->data.follow.from_id * 10000 +
                     event->data.follow.to_id] = 1;
    fprintf(fout,
            "\"%u\",\"%u\",\"%u\",\"%s\"\n",
            event->type,
            event->data.follow.from_id + 1,
            event->data.follow.to_id + 1,
            event->data.follow.time_initiated);
    return 0;
}
