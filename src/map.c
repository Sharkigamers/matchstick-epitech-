/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** map
*/

#include "my.h"

void find_nb_stick(mb_t *mb, char **game_table, int i)
{
    int line = i + 1;

    mb->nb_stick = 0;
    for (int j = 0; game_table[line][j] != '\0'; j++) {
        if (game_table[line][j] == '|')
            mb->nb_stick++;
    }
}

void fill_nb_stick(mb_t *mb, int i, int j)
{
    if ((mb->nb_stick % my_power(2, j)) != mb->nb_stick) {
        mb->tab[i][j] = 1;
        mb->nb_stick = mb->nb_stick % my_power(2, j);
    }
    else
        mb->tab[i][j] = 0;
}

void fill_map(mb_t *mb, char **game_table, int nb_line)
{
    int i;
    int j;

    mb->tab = malloc(sizeof(int *) * (nb_line + 2));
    mb->tab[nb_line + 1] = NULL;
    for (i = 0; i != nb_line; i++) {
        mb->tab[i] = malloc(sizeof(int) * 8);
        find_nb_stick(mb, game_table, i);
        for (j = 7; j >= 0; j--) {
            fill_nb_stick(mb, i, j);
        }
    }
    mb->tab[i] = malloc(sizeof(int) * 8);
    for (int k = 0; k <= 7; k++) {
        mb->nb_stick = 0;
        for (int l = 0; l != nb_line; l++)
            mb->tab[l][k] == 1 ? mb->nb_stick++ : 0;
        mb->tab[i][k] = mb->nb_stick;
    }
}
