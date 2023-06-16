/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of sounds
*/

#include "../../include/my_csfml.h"

audio_t *my_audio_init(char *file)
{
    audio_t *audio = malloc(sizeof(audio_t));
    audio->sound = sfSound_create();
    audio->buffer = sfSoundBuffer_createFromFile(file);
    sfSound_setBuffer(audio->sound, audio->buffer);
    audio->loop = 0;
    return (audio);
}

audio_t **my_audio_list_init(char *file)
{
    char **tab = my_str_to_array(my_file_to_str(file), "\n");
    audio_t **audio_list = malloc(sizeof(audio_t) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        audio_list[i] = my_audio_init(tab[i]);
    }
    audio_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (audio_list);
}

void my_audio_play(audio_t *audio)
{
    if (sfSound_getStatus(audio->sound) != sfPlaying) {
        sfSound_play(audio->sound);
    }
}

void my_audio_list_destroy(audio_t **audio_list)
{
    for (int i = 0; audio_list[i] != NULL; i++) {
        my_audio_destroy(audio_list[i]);
    }
    free(audio_list);
}

void my_audio_destroy(audio_t *audio)
{
    sfSoundBuffer_destroy(audio->buffer);
    sfSound_destroy(audio->sound);
    free(audio);
}
