/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** main game
*/

#include "snake.h"

int game_done(WINDOW *win, node_t *head)
{
    for (node_t *tmp = head; tmp; tmp = tmp->next) {
        if (tmp->pos.x <= 0 || tmp->pos.x >= WIN_WIDTH - 1)
            return (1);
        else if (tmp->pos.y <= 0 || tmp->pos.y >= WIN_HEIGHT - 1)
            return (1);
    }
    for (node_t *tmp = head->next; tmp->next; tmp = tmp->next) {
        if (tmp->pos.x == head->pos.x && tmp->pos.y == head->pos.y)
            return (1);
    }
    return (0);
}

WINDOW *create_window(int height, int width)
{
    WINDOW *win = newwin(height, width, 5, 5);

    if (!win)
        return (0);
    box(win, 0, 0);
    keypad(win, TRUE);
    nodelay(win, TRUE);
    return (win);
}

int end_game(WINDOW *win, node_t *head)
{
    node_t *tmp;

    delwin(win);
    endwin();
    for (tmp = head; tmp; tmp = tmp->next);
    for (tmp = tmp; tmp; tmp = tmp->prev)
        free(tmp);
    return (0);
}

int snake(char *prev_score)
{
    node_t *head = create_head(5, 5);
    WINDOW *win = create_window(WIN_HEIGHT, WIN_WIDTH);
    vector_t speed = {0, 1};
    vector_t coco = {random_i(2, WIN_WIDTH - 3), random_i(2, WIN_HEIGHT - 3)};
    int score = 0;

    if (!win || !head)
        return (end_game(win, head));
    while (!game_done(win, head)) {
        get_input(win, &speed);
        if (eat_coco(win, head, &coco))
            score += 10;
        draw_coconut(win, &coco);
        move_node(win, head, speed);
        wrefresh(win);
        draw_win(win, score, prev_score);
        usleep(RATE);
    }
    end_game(win, head);
    return (score);
}
