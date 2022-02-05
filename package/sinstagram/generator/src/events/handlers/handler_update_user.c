#include "handler_update_user.h"

int handle_update_user(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (!model->cnt_active_user) {
        return 2;
    }
    fprintf(fout, "\"%u\",\"%u\",\"%s\",%hhd,%hhd,%hhd,\"%s\"\n",
            event->type,
            event->data.update_user.id + 1,
            event->data.update_user.name,
            event->data.update_user.sex,
            event->data.update_user.gender,
            event->data.update_user.education_level,
            event->data.update_user.dob);
    return 0;
}
