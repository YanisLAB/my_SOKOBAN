/*
** EPITECH PROJECT, 2020
** Projets
** File description:
** my_str_to_word_array.c
*/

#include "all.h"

void check_str(char **array, char *temp, int *ii, int *k)
{
    if (*ii != 0) {
        temp[*ii] = '\0';
        *ii = 0;
        array[*k] = my_strdup(temp);
        *k += 1;
    }
}

char **my_str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char temp[512];
    int i = 0;
    int ii = 0;
    int k = 0;

    for (; str[i] != '\0'; i += 1) {
        if (str[i] != '\n') {
            temp[ii] = str[i];
            ii += 1;
        } else {
            check_str(array, temp, &ii, &k);
        }
    }
    check_str(array, temp, &ii, &k);
    array[k] = NULL;
    return (array);
}