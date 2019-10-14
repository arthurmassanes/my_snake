/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** drawing windows and game objects
*/

#include "snake.h"

int eat_coco(WINDOW *win, node_t *head, vector_t *coconut)
{
    node_t *tmp = head;

    if (head->pos.x == coconut->x && head->pos.y == coconut->y) {
        for (tmp = tmp; tmp->next; tmp = tmp->next);
        append_node(head, tmp->pos.x, tmp->pos.y + 1);
        coconut->x = random_i(2, WIN_WIDTH - 3);
        coconut->y = random_i(2, WIN_HEIGHT - 3);
        return (1);
    } else
        return (0);
}

void draw_coconut(WINDOW *win, vector_t *coconut)
{
    wattron(win, COLOR_PAIR(RED));
    mvwprintw(win, coconut->y, coconut->x, COCO);
    wattroff(win, COLOR_PAIR(RED));
}

void draw_win(WINDOW *win, int score, char *prev)
{
    wclear(win);
    box(win, 0, 0);
    mvprintw(4, 6, "Score: %d", score);
    wattron(stdscr, COLOR_PAIR(YELLOW));
    mvwprintw(stdscr, WIN_HEIGHT + 5, 6, "Best score: %s", prev);
    wattroff(stdscr, COLOR_PAIR(YELLOW));
    refresh();
}
