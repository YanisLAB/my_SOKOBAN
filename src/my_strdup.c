/*
** EPITECH PROJECT, 2020
** Repo_my_ls
** File description:
** my_strdup.c
*/

#include "all.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    return (my_strcpy(result, str));
}