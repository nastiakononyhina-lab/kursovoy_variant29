
#include <stdio.h>

typedef struct {
    char timestamp[20];
    char level[10];
    char message[256];
} Event;

void print_event(const Event *event)
{
    printf("Время: %s\n", event->timestamp);
    printf("Уровень: %s\n", event->level);
    printf("Событие: %s\n", event->message);
}

int main(void)
{
    Event event = {
        "2026-11-20 18:00",
        "INFO",
        "Cache server started"
    };

    printf("Архив событий кэш-сервера\n");
    print_event(&event);

    return 0;
}

