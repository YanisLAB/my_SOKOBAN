/*
** EPITECH PROJECT, 2021
** BS_sokoban
** File description:
** tools.c
*/

#include "all.h"

void destroy_all(map_t *map)
{
    for (int i = 0; i < map->lmax; i++) {
        free(map->cpfmap[i]);
    }
    for (int i = 0; i < map->lmax; i++) {
        free(map->fmap[i]);
    }
    free(map->cpfmap);
    free(map->fmap);
    free(map->save);
    close(map->fd);
}

void counter(map_t *map)
{
    int c = 0;
    map->cmax = 0;
    map->lmax = 0;
    for (int i = 0; map->save[i] != '\0'; i++) {
        if (map->save[i] == '\n') {
            map->lmax += 1;
            c = 0;
            continue;
        }
        c += 1;
        if (c > map->cmax)
            map->cmax = c;
    }
}

void helper(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map,");
    my_putstr(" containing ‘#’ for walls,\n");
    my_putstr("\t\t‘P’ for the player,");
    my_putstr(" ‘X’ for boxes and ‘O’ for storage locations.\n");
    exit(0);
}

void error_handler(int ac, char **av, map_t *maps)
{
    if (ac != 2)
        exit(84);
    if (my_strcmp(av[1], "-h") == 0)
        helper();
    maps->fd = open(av[1], O_RDONLY);
    if (maps->fd == -1)
        exit(84);
}