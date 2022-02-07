#include "handler_create_user.h"

int handle_create_user(struct Event *event, struct Model *model, FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    if (model->cnt_user >= 10000) {
        return 2;
    }
    ++model->cnt_user;
    ++model->cnt_active_user;
    *(model->users_end++) = 1;
    fprintf(fout, "\"%u\",\"%s\",\"%hhd\",\"%hhd\",\"%hhd\",\"%s\",\"%s\"\n",
            event->type,
            event->data.create_user.name,
            event->data.create_user.sex,
            event->data.create_user.gender,
            event->data.create_user.education_level,
            event->data.create_user.dob,
            event->data.create_user.created);
    return 0;
}
