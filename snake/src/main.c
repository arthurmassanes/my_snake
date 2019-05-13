/*
** EPITECH PROJECT, 2019
**  snake
** File description:
** main func calling snake
*/

#include "snake.h"

int random_i(int min, int max)
{
    int nb = rand() % max;

    return (nb + min);
}

void init_game(void)
{
    srand(time(NULL));
    initscr();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

}

int main(int ac, char **av)
{
    int score;

    init_game();
    score = snake();
    printf("Your score: %d\n", score);
    return (0);
}
