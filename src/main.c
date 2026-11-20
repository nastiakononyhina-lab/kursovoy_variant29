
#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int node;
    int hits;
    int misses;
} Event;

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

int read_event(const char *line, Event *event)
{
    if (line == NULL || event == NULL) {
        return 0;
    }

    if (sscanf(line, "%d:%d %d %d %d",
               &event->hours,
               &event->minutes,
               &event->node,
               &event->hits,
               &event->misses) != 5) {
        return 0;
    }

    return is_event_valid(event);
}

void print_event(const Event *event)
{
    printf("Время: %02d:%02d\n", event->hours, event->minutes);
    printf("Узел: %d\n", event->node);
    printf("Попадания: %d\n", event->hits);
    printf("Промахи: %d\n", event->misses);
}

int main(void)
{
    FILE *file = fopen("events.txt", "r");

    if (file == NULL) {
        printf("Не удалось открыть файл events.txt\n");
        return 1;
    }

    char line[100];
    Event event;

    printf("Архив событий кэш-сервера\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        if (read_event(line, &event)) {
            print_event(&event);
            printf("---\n");
        } else {
            printf("Пропущена некорректная строка.\n");
        }
    }

    fclose(file);
    return 0;
}
