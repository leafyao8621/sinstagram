#ifndef _EVENTS_H_
#define _EVENTS_H_

#include <stdio.h>
#include <time.h>

#include "../util/generator.h"
#include "../model/model.h"

#define EVENT_CREATE_USER 0
#define EVENT_REMOVE_USER 1
#define EVENT_UPDATE_USER 2
#define EVENT_CREATE_POST 3
#define EVENT_REMOVE_POST 4
#define EVENT_CREATE_COMMENT 5
#define EVENT_REMOVE_COMMENT 6
#define EVENT_FOLLOW 7
#define EVENT_UNFOLLOW 8
#define EVENT_LIKE_POST 9
#define EVENT_UNLIKE_POST 10

struct Event {
    char type;
    union {
        struct {
            char name[100];
            char sex;
            char gender;
            char education_level;
            char dob[100];
            char created[100];
        } create_user;
        struct {
            unsigned id;
        } remove_user;
        struct {
            unsigned id;
            char name[100];
            char sex;
            char gender;
            char education_level;
            char dob[100];
        } update_user;
        struct {
            unsigned user_id;
            char textual_content[1000];
            char time_posted[100];
            char url[5][1000];
        } create_post;
        struct {
            char id;
        } remove_post;
        struct {
            unsigned post_id;
            unsigned user_id;
            char textual_content[1000];
            char time_commented[100];
            char url[5][1000];
        } create_comment;
        struct {
            unsigned id;
        } remove_comment;
        struct {
            unsigned from_id;
            unsigned to_id;
            char time_initiated[100];
        } follow;
        struct {
            unsigned from_id;
            unsigned to_id;
        } unfollow;
        struct {
            unsigned post_id;
            unsigned user_id;
            char time_liked[100];
        } like_post;
        struct {
            unsigned post_id;
            unsigned user_id;
        } unlike_post;
    } data;
};

int event_generate(struct Event *event,
                   struct Model *model,
                   struct MT19937 *gen,
                   time_t timestamp);
int event_handle(struct Event *event,
                 struct Model *model,
                 FILE *fout);

#endif
