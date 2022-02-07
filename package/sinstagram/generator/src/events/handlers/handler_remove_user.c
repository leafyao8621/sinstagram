#include "handler_remove_user.h"

int handle_remove_user(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_user) {
        return 2;
    }
    --(model->cnt_active_user);
    model->users[event->data.remove_user.id] = 0;
    fprintf(fout, "\"%u\",\"%u\"\n",
            event->type,
            event->data.remove_user.id + 1);
    return 0;
}
