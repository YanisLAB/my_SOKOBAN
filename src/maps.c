/*
** EPITECH PROJECT, 2021
** Repo_My_sokoban
** File description:
** maps.c
*/

#include "all.h"

void check_map(map_t *map)
{
    for (int i = 0; map->fmap[i] != NULL; i++) {
        for (int n = 0; map->fmap[i][n] != '\0'; n++) {
            if (map->cpfmap[i][n] == 'O' && map->fmap[i][n] == ' ')
                map->fmap[i][n] = map->cpfmap[i][n];
        }
    }
}

void find_player(map_t *map, pos_t *pos)
{
    for (int i = 0; map->fmap[i] != NULL; i++) {
        for (int n = 0; map->fmap[i][n] != '\0'; n++) {
            if (map->fmap[i][n] == 'P') {
                pos->px = n;
                pos->py = i;
                return;
            }
        }
    }
}

void reset_map(map_t *map)
{
    for (int i = 0; map->fmap[i] != NULL; i++) {
        for (int n = 0; map->fmap[i][n] != '\0'; n++) {
            map->fmap[i][n] = map->cpfmap[i][n];
        }
    }
}

bool check_char(char *map)
{
    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] != ' ' && map[i] != 'X' && map[i] != '#'
        && map[i] != 'O' && map[i] != '\n' && map[i] != 'P')
            return (false);
    }
    return (true);
}

void map_gen(map_t *map, char *av)
{
    struct stat sb;
    stat(av, &sb);
    map->save = malloc(sizeof(char) * sb.st_size + 1);
    if (read(map->fd, map->save, sb.st_size) == -1)
        exit(84);
    map->save[sb.st_size] = '\0';
    if (check_char(map->save) == false)
        exit(84);
}