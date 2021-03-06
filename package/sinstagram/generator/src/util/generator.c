#include <math.h>
#include <time.h>
#include "generator.h"

int generator_generate_offset(struct MT19937 *gen, unsigned *out) {
    if (!gen || !out) {
        return 1;
    }
    *out = -log(mt19937_gen(gen) / (double)0xffffffff) * 600;
    return 0;
}

int generator_generate_string(struct MT19937 *gen, char *out, unsigned len) {
    if (!gen || !out || !len) {
        return 1;
    }
    unsigned actual_len = (mt19937_gen(gen) % len) + 1;
    char *iter = out;
    for (unsigned i = 0; i < actual_len; ++i, ++iter) {
        *iter = mt19937_gen(gen) % 94 + 33;
        if (*iter == '"' && i == actual_len - 1) {
            for (*iter = mt19937_gen(gen) % 94 + 33;
                 *iter == '"';
                 *iter = mt19937_gen(gen) % 94 + 33);
        } else if (*iter == '"') {
            ++i;
            *(++iter) = '"';
        } else if (*iter == ',') {
            if (iter[-1] == '"') {
                *iter = '*';
            }
        }
    }
    *iter = 0;
    return 0;
}

int generator_generate_dob(struct MT19937 *gen, char *out) {
    if (!gen || !out) {
        return 1;
    }
    time_t now = time(0);
    time_t res = mt19937_gen(gen) % now;
    struct tm *info = gmtime(&res);
    strftime(out, 99, "%Y-%m-%d", info);
    return 0;
}

int generator_generate_enum(struct MT19937 *gen, char ub, char *out) {
    if (!gen || !out) {
        return 1;
    }
    *out = mt19937_gen(gen) % (ub + 1);
    return 0;
}

int generator_generate_idx(struct MT19937 *gen, unsigned ub, unsigned *out) {
    if (!gen || !out) {
        return 1;
    }
    *out = mt19937_gen(gen) % ub;
    return 0;
}

int generator_generate_event_type(struct MT19937 *gen, char *out) {
    static double cdf[11] = {
        0.499,
        0.5,
        0.6,
        0.699,
        0.7,
        0.799,
        0.8,
        0.899,
        0.9,
        0.999,
        1
    };
    if (!gen || !out) {
        return 1;
    }
    double u = mt19937_gen(gen) / (double)0xffffffff;
    double *iter = cdf;
    *out = 0;
    for (; *iter < u; ++(*out), ++iter);
    return 0;
}
