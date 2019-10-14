/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** linked list creaation
*/

#include "snake.h"

node_t *create_head(int x, int y)
{
    node_t *head = malloc(sizeof(node_t));

    if (!head)
        return (0);
    head->pos.x = x;
    head->pos.y = y;
    head->prev = 0;
    append_node(head, x, y + 1);
    append_node(head, x, y + 2);
    return (head);
}

void move_node(WINDOW *win, node_t *head, vector_t speed)
{
    node_t *tmp = head;
    vector_t save = {head->pos.x, head->pos.y};
    vector_t save2 = {head->pos.x, head->pos.y};

    tmp->pos.x += speed.x;
    tmp->pos.y += speed.y;
    tmp = tmp->next;
    for (tmp = tmp; tmp; tmp = tmp->next) {
        save.x = tmp->pos.x;
        save.y = tmp->pos.y;
        tmp->pos.x = save2.x;
        tmp->pos.y = save2.y;
        save2.x = save.x;
        save2.y = save.y;
        wattron(win, COLOR_PAIR(GREEN));
        mvwprintw(win, tmp->pos.y, tmp->pos.x, SNAKE_BODY);
        wattroff(win, COLOR_PAIR(GREEN));
    }
}

void append_node(node_t *head, int x, int y)
{
    node_t *tmp = head;

    for (tmp = tmp; tmp && tmp->next; tmp = tmp->next);
    tmp->next = malloc(sizeof(node_t));
    if (!tmp->next)
        return;
    tmp->next->pos.x = x;
    tmp->next->pos.y = y;
    tmp->next->next = 0;
    tmp->next->prev = tmp;
}
