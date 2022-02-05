#include "initializers.h"
#include "initializer_create_user.h"
#include "initializer_remove_user.h"
#include "initializer_update_user.h"
#include "initializer_create_post.h"
#include "initializer_like_post.h"
#include "initializer_unlike_post.h"
#include "initializer_follow.h"
#include "initializer_unfollow.h"
#include "initializer_remove_post.h"
#include "initializer_create_comment.h"
#include "initializer_remove_comment.h"

int (*initializers[11])(struct Event *event,
                        struct Model *model,
                        struct MT19937 *gen,
                        char *timestamp) = {
    initialize_create_user,
    initialize_remove_user,
    initialize_update_user,
    initialize_create_post,
    initialize_remove_post,
    initialize_create_comment,
    initialize_remove_comment,
    initialize_follow,
    initialize_unfollow,
    initialize_like_post,
    initialize_unlike_post
};
