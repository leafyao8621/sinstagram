#include "model.h"

int model_initialize(struct Model *model) {
    if (!model) {
        return 1;
    }
    model->users_end = model->users;
    model->posts_end = model->posts;
    model->post_comments_end = model->post_comments;
    return 0;
}

int model_check_condition(struct Model *model, char *out) {
    if (!model || !out) {
        return 1;
    }
    *out = 0;
    if (model->cnt_user >= 10000 &&
        !model->cnt_active_user) {
        *out = 1;
    }
    return 0;
}
