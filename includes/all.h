/*
** EPITECH PROJECT, 2020
** BS_sokoban
** File description:
** all.h
*/

#ifndef __ALL_H__
#define __ALL_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

/* ~~~~~~~~~{ Struct }~~~~~~~~~ */
typedef struct maps {
    char **fmap;
    char **cpfmap;
    char *save;
    int fd;
    int lmax;
    int cmax;
}map_t;

typedef struct pos {
    bool box;
    int px;
    int py;
    int px1;
    int py1;
    int bx1;
    int by1;
}pos_t;

/* ~~~~~~~~~{ LIB }~~~~~~~~~ */
void my_putchar(char c);
char *my_strdup(char *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char *str);

/* ~~~~~~~~~{ Tools }~~~~~~~~~ */
void helper(void);
void counter(map_t *map);
void destroy_all(map_t *map);
void error_handler(int ac, char **av, map_t *maps);

/* ~~~~~~~~~{ Maps }~~~~~~~~~ */
void check_map(map_t *map);
void reset_map(map_t *map);
void map_gen(map_t *map, char *av);
void find_player(map_t *map, pos_t *pos);
void reset_find_player(map_t *map, pos_t *pos);

/* ~~~~~~~~~{ Game }~~~~~~~~~ */
void move_player(map_t *map, pos_t *pos, int h);

#endif