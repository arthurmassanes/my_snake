/*
** ARTHUR MASSANES PROJECT, 2019
**  snake
** File description:
** main func calling snake
*/

#include "snake.h"

char *get_score_file(void)
{
    struct passwd *pw = getpwuid(getuid());
    char *file_name = strcat(pw->pw_dir, "/.snake_scores");

    if (!file_name)
        return (0);
    return (file_name);
}

char *get_previous_score(char *file)
{
    FILE *f = fopen(file, "r");
    char *score = strdup("No available best score");
    size_t sz;
    int rd;

    if (!f)
        return (score);
    rd = getline(&score, &sz, f);
    if (rd == EOF)
        return (0);
    return (score);
}

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
    char *score_file = get_score_file();
    char *prev_score = get_previous_score(score_file);

    if (!score_file || !prev_score)
        return (EXIT_ERROR);
    init_game();
    score = snake(prev_score);
    printf("Your score: %d\n", score);
    return (save_score(score, score_file));
}
