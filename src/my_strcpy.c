/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** copy string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i]; i = i + 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
