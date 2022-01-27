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
