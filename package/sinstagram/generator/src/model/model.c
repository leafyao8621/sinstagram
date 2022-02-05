#include <string.h>
#include "model.h"

int model_initialize(struct Model *model) {
    if (!model) {
        return 1;
    }
    model->cnt_user = model->cnt_active_user = 0;
    model->cnt_posts = model->cnt_active_posts = 0;
    model->cnt_post_comments = model->cnt_active_post_comments = 0;
    model->cnt_likes = 0;
    model->cnt_followings = 0;
    memset(model->users, 0, 10000);
    memset(model->posts, 0, 10000);
    memset(model->post_comments, 0, 1000000);
    memset(model->following, 0, 100000000);
    memset(model->post_likes, 0, 10000000000);
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
