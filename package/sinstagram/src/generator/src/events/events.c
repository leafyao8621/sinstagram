#include "events.h"
#include "handlers/handlers.h"
#include "initializers/initializers.h"

int event_generate(struct Event *event,
                   struct Model *model,
                   struct MT19937 *gen,
                   time_t timestamp) {
    if (!event || !model || !gen) {
        return 1;
    }
    char buf[100];
    struct tm *info;
    info = gmtime(&timestamp);
    strftime(buf, 99, "%Y-%m-%dT%H:%M:%SZ", info);
    puts(buf);
    initializers[(unsigned long)event->type](event, model, gen, buf);
    return 0;
}

int event_handle(struct Event *event,
                 struct Model *model,
                 FILE *fout) {
    if (!event || !model || !fout) {
        return 1;
    }
    return handlers[(unsigned long)event->type](event, model, fout);
}
