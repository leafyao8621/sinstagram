#include "simulator.h"

int simulator_initialize(struct Simulator *simulator,
                         time_t start_time,
                         unsigned seed,
                         const char *dir) {
    if (!simulator || !dir) {
        return 1;
    }
    simulator->time_now = start_time;
    mt19937_initialize(&simulator->gen, seed);
    model_initialize(&simulator->model);
    simulator->dir = dir;
    return 0;
}

int simulator_run(struct Simulator *simulator, unsigned iter, char verbose) {
    if (!simulator) {
        return 1;
    }
    char buf_path[1000];
    FILE *fout = 0;
    char cond = 0;
    for (unsigned i = 0; i < iter; ++i) {
        model_check_condition(&simulator->model, &cond);
        if (cond) {
            break;
        }
        if (verbose) {
            printf("iter %u %u %u %u %u %u %u\n",
                   i,
                   simulator->model.cnt_user,
                   simulator->model.cnt_active_user,
                   simulator->model.cnt_posts,
                   simulator->model.cnt_active_posts,
                   simulator->model.cnt_likes,
                   simulator->model.cnt_followings);
        }
        if (!(i % 100)) {
            if (fout) {
                fclose(fout);
            }
            sprintf(buf_path, "%s/%d.csv", simulator->dir, i / 100);
            fout = fopen(buf_path, "w");
        }
        unsigned offset = 0;
        generator_generate_offset(&simulator->gen, &offset);
        simulator->time_now += offset;
        int ret = event_generate(&simulator->event,
                                 &simulator->model,
                                 &simulator->gen,
                                 simulator->time_now);
        if (ret == 2) {
            break;
        }
        event_handle(&simulator->event, &simulator->model, fout);
    }
    if (fout) {
        fclose(fout);
    }
    return 0;
}
