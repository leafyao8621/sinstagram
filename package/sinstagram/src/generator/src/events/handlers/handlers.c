#include "handlers.h"
#include "handler_create_user.h"
#include "handler_remove_user.h"
#include "handler_update_user.h"
#include "handler_create_post.h"

int (*handlers[11])(struct Event *event,
                    struct Model *model,
                    FILE *fout) = {
    handle_create_user,
    handle_remove_user,
    handle_update_user,
    handle_create_post,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
