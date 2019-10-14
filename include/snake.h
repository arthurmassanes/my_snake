/*
** ARTHUR MASSANES PROJECT, 2019
**  snake
** File description:
** include
*/

#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct node_s {
    vector_t pos;
    struct node_s *next;
    struct node_s *prev;
} node_t;

#define EXIT_ERROR 84
#define RATE 100000
#define WIN_HEIGHT 25
#define WIN_WIDTH 50
#define COCO "o"
#define SNAKE_BODY "*"

//COLORS
#define RED 1
#define YELLOW 2
#define MAGENTA 3
#define GREEN 4

int snake(char *);
void append_node(node_t *head, int x, int y);
void move_node(WINDOW *win, node_t *head, vector_t speed);
void get_input(WINDOW *win, vector_t *);
node_t *create_head(int x, int y);
void draw_coconut(WINDOW *win, vector_t *);
int eat_coco(WINDOW *, node_t *, vector_t *);
void draw_win(WINDOW *, int, char *);
int random_i(int, int);
int save_score(int, char *);
int is_num(char c);
int fs_get_number_len(int fd);
int get_nbr(char *str);
int fs_get_number_from_first_line(int fd, char *file_name);

#endif
