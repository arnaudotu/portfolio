/*
** EPITECH PROJECT, 2022
** my_csfml_time.c
** File description:
** structure and functions related to time
*/

#include "../../include/my_csfml.h"

void my_time_wait(window_t *window, float sec)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;
    while (seconds < sec && sfRenderWindow_isOpen(window->screen)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        my_event_check(window);
    }
    sfClock_destroy(clock);
}

void my_audio_wait_end(audio_t *audio)
{
    if (sfSound_getStatus(audio->sound) == sfPlaying) {
        my_audio_wait_end(audio);
    }
}
