
#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int node;
    int hits;
    int misses;
} Event;

void print_event(const Event *event);

int main(void)
{
    Event event = {10, 30, 1, 120, 8};

    printf("Архив событий кэш-сервера\n");
    print_event(&event);

    return 0;
}

void print_event(const Event *event)
{
    printf("Время: %02d:%02d\n", event->hours, event->minutes);
    printf("Узел: %d\n", event->node);
    printf("Попадания: %d\n", event->hits);
    printf("Промахи: %d\n", event->misses);
}
