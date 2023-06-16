/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

world_t *world_init(char *info, char *tilemap)
{
    world_t *world = malloc(sizeof(world_t));
    char **tab = my_str_to_array(info, ";");
    world->bg_list = my_object_list_init(tab[0]);
    world->npc_list = my_object_list_init(tab[1]);
    world->map = my_tilemap_init(tilemap);
    world->tp_list = teleport_list_init(tab[2]);
    world->battle = my_str_to_int(tab[3]);
    world->npc_fct = NULL;
    my_free_array(tab);
    return (world);
}

world_t **world_list_init(char *all_info, char *all_tmap)
{
    char **tab_world = my_str_to_array(my_file_to_str(all_info), "\n");
    char **tab_map = my_str_to_array(my_file_to_str(all_tmap), "\n");
    world_t **world_list = malloc(sizeof(world_t) * my_arraylen(tab_world));
    for (int i = 0; i < my_arraylen(tab_world); i++) {
        world_list[i] = world_init(tab_world[i], tab_map[i]);
    }
    world_list[my_arraylen(tab_world)] = NULL;
    my_free_array(tab_world);
    my_free_array(tab_map);
    return (world_list);
}

void world_show(game_t *G, world_t *world)
{
    my_tilemap_show(world->map, G->win);
    my_object_list_show(world->bg_list, G->win);
    my_object_list_animate(world->bg_list);
    for (int i = 0; world->npc_list[i] != NULL; i++) {
        if (world->npc_switch[i] == 0) {
            my_object_show(world->npc_list[i], G->win);
        }
    }
    animate_npc(G);
    handle_teleport(G);
    my_object_show(G->player->obj, G->win);
    show_bubble_speach(G);
}

void world_list_destroy(world_t **world_list)
{
    for (int i = 0; world_list[i] != NULL; i++) {
        world_destroy(world_list[i]);
    }
    free(world_list);
}

void world_destroy(world_t *world)
{
    my_object_list_destroy(world->bg_list);
    my_object_list_destroy(world->npc_list);
    free(world->npc_switch);
    my_tilemap_destroy(world->map);
    teleport_list_destroy(world->tp_list);
    world_dialogue_destroy(world->npc_speak);
    if (world->npc_fct != NULL) {
        free(world->npc_fct);
    }
}
