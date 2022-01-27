#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include "mt19937.h"

int generator_generate_offset(struct MT19937 *gen, unsigned *out);
int generator_generate_string(struct MT19937 *gen, char *out, unsigned len);
int generator_generate_dob(struct MT19937 *gen, char *out);

#endif
