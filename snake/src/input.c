/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** input managing
*/

#include "snake.h"

void get_input(WINDOW *win, vector_t *speed)
{
    int c = wgetch(win);
    int dir[] = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 0};
    vector_t output[] = {{0, -1},{0, 1},{-1, 0},{1, 0}};

    for (int i = 0; dir[i]; i++) {
        if (c == dir[i]) {
            speed->x = output[i].x;
            speed->y = output[i].y;
        }
    }
}
