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
    generator_generate_event_type(gen, &event->type);
    int ret = initializers[(unsigned long)event->type](event, model, gen, buf);
    if (ret == 2) {
        switch (event->type) {
        case EVENT_CREATE_USER:
            event->type = EVENT_UPDATE_USER;
            ret = initializers[EVENT_UPDATE_USER](event, model, gen, buf);
            if (ret == 2) {
                return 2;
            }
            break;
        case EVENT_REMOVE_USER:
            event->type = EVENT_CREATE_USER;
            ret = initializers[EVENT_CREATE_USER](event, model, gen, buf);
            if (ret == 2) {
                return 2;
            }
            break;
        }
    }
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
