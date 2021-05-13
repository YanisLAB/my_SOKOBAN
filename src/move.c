/*
** EPITECH PROJECT, 2021
** Repo_My_sokoban
** File description:
** move.c
*/

#include "all.h"

bool check_move(map_t *map, pos_t *pos)
{
    if (map->fmap[pos->py1][pos->px1] == '#')
        return (false);
    if (map->fmap[pos->py1][pos->px1] == ' '
    || map->fmap[pos->py1][pos->px1] == 'O')
        return (true);
    if (map->fmap[pos->py1][pos->px1] == 'X') {
        if (map->fmap[pos->by1][pos->bx1] == '#'
        || map->fmap[pos->by1][pos->bx1] == 'X')
            return (false);
        if (map->fmap[pos->by1][pos->bx1] == ' '
        || map->fmap[pos->by1][pos->bx1] == 'O') {
            pos->box = true;
            return (true);
        }
    }
    return (true);
}

void move4_player(map_t *map, pos_t *pos, int d)
{
    if (d == 1) {
        if (check_move(map, pos) == true) {
            if (pos->box == true) {
                map->fmap[pos->by1][pos->bx1] = 'X';
                pos->box = false;
            }
            map->fmap[pos->py1][pos->px1] = 'P';
            map->fmap[pos->py][pos->px] = ' ';
            pos->px = pos->px1;
            pos->py = pos->py1;
        }
    }
}

void move3_player(map_t *map, pos_t *pos, int h, int d)
{
    if (h == KEY_LEFT) {
        pos->px1 = pos->px - 1;
        pos->py1 = pos->py;
        pos->bx1 = pos->px1 - 1;
        pos->by1 = pos->py1;
        d = 1;
    }
    if (h == KEY_RIGHT) {
        pos->px1 = pos->px + 1;
        pos->py1 = pos->py;
        pos->bx1 = pos->px1 + 1;
        pos->by1 = pos->py1;
        d = 1;
    }
    move4_player(map, pos, d);
}

void move2_player(map_t *map, pos_t *pos, int h, int d)
{
    if (h == KEY_UP) {
        pos->px1 = pos->px;
        pos->py1 = pos->py - 1;
        pos->bx1 = pos->px1;
        pos->by1 = pos->py1 - 1;
        d = 1;
    }
    if (h == KEY_DOWN) {
        pos->px1 = pos->px;
        pos->py1 = pos->py + 1;
        pos->bx1 = pos->px1;
        pos->by1 = pos->py1 + 1;
        d = 1;
    }
    move3_player(map, pos, h, d);
}

void move_player(map_t *map, pos_t *pos, int h)
{
    int d = 0;
    if (h == 27) {
        clear();
        refresh();
        destroy_all(map);
        endwin();
        exit(0);
    }
    if (h == 32) {
        reset_map(map);
        find_player(map, pos);
    }
    move2_player(map, pos, h, d);
}