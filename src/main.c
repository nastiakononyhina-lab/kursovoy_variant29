
#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int node;
    int hits;
    int misses;
} Event;

void print_event(const Event *event);


int is_event_valid(const Event *event)
{
    if (event == NULL) {
        return 0;
    }

    if (event->hours < 0 || event->hours > 23) {
        return 0;
    }

    if (event->minutes < 0 || event->minutes > 59) {
        return 0;
    }

    if (event->node < 0 || event->hits < 0 || event->misses < 0) {
        return 0;
    }

    return 1;
}



int main(void)
{
    Event event = {10, 30, 1, 120, 8};

    printf("Архив событий кэш-сервера\n");

    if (is_event_valid(&event)) {
        printf("Событие корректно.\n");
        print_event(&event);
    } else {
        printf("Ошибка: некорректные данные события.\n");
    }

    return 0;
}


void print_event(const Event *event)
{
    printf("Время: %02d:%02d\n", event->hours, event->minutes);
    printf("Узел: %d\n", event->node);
    printf("Попадания: %d\n", event->hits);
    printf("Промахи: %d\n", event->misses);
}
