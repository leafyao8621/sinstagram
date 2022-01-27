#ifndef _MODEL_H_
#define _MODEL_H_

struct Model {
    unsigned cnt_user;
    unsigned cnt_posts;
    unsigned cnt_post_comments;
    char users[10000], *users_end;
    char posts[1000000], *posts_end;
    char post_comments[1000000], *post_comments_end;
    char following[100000000];
    char post_likes[10000000000];
};

int model_initialize(struct Model *model);

#endif
