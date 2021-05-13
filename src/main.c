/*
** EPITECH PROJECT, 2021
** BS_sokoban
** File description:
** main.c
*/

#include "all.h"

void event(map_t *map, int s)
{
    clear();
    for (int i = map->lmax/2*-1, e = 0; i <= map->lmax / 2; i += 1, e += 1)
        mvprintw(LINES/2+i, (COLS / 2) - (map->cmax / 2), map->fmap[e]);
    refresh();
    destroy_all(map);
    endwin();
    exit(s);
}

void check_lose(map_t *map)
{
    int t = 0;
    int e = 0;
    for (int i = 0; map->fmap[i] != NULL; i++) {
        for (int n = 0; map->fmap[i][n] != '\0'; n++) {
            if (map->fmap[i][n] == 'X') {
                if ((map->fmap[i][n + 1] == '#' || map->fmap[i][n - 1] == '#'
                || map->fmap[i][n + 1] == 'X' || map->fmap[i][n - 1] == 'X')
                && (map->fmap[i + 1][n] == '#' || map->fmap[i - 1][n] == '#'
                || map->fmap[i + 1][n] == 'X' || map->fmap[i - 1][n] == 'X'))
                    t += 1;
            }
            if (map->fmap[i][n] == 'X')
                e += 1;
        }
    }
    if (t == e)
        event(map, 1);
}

void check_statut(map_t *map)
{
    int t = 0;
    int e = 0;
    for (int i = 0; map->fmap[i] != NULL; i++) {
        for (int n = 0; map->fmap[i][n] != '\0'; n++) {
            if (map->cpfmap[i][n] == 'O' && map->fmap[i][n] == 'X')
                t += 1;
            if (map->fmap[i][n] == 'X')
                e += 1;
        }
    }
    if (t == e)
        event(map, 0);
    check_lose(map);
}

void sokoban(map_t *map, pos_t *pos)
{
    initscr();
    int n = 0;
    char err[30] = "Please enlarge the terminal !\0";
    curs_set(0);
    keypad(stdscr, TRUE);
    while (true) {
        clear();
        if (LINES < map->lmax || COLS < map->cmax) {
            mvprintw(LINES/2, (COLS / 2) - 14, err);
        } else {
            for (int i = map->lmax/2*-1; map->fmap[n] != NULL; i += 1, n += 1)
                mvprintw(LINES/2+i, (COLS / 2) - (map->cmax / 2), map->fmap[n]);
        }
        move_player(map, pos, getch());
        check_map(map);
        check_statut(map);
        refresh();
        n = 0;
    }
    endwin();
}

int main(int ac, char **av)
{
    map_t map;
    pos_t pos;
    error_handler(ac, av, &map);
    map_gen(&map, av[1]);
    counter(&map);
    pos.box = false;
    map.fmap = my_str_to_word_array(map.save);
    map.cpfmap = my_str_to_word_array(map.save);
    find_player(&map, &pos);
    sokoban(&map, &pos);
    destroy_all(&map);
    return (0);
}