/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** saving score in a file
*/

#include "snake.h"

int write_file(char *file_name, int score)
{
    char *name = strdup("hello");
    size_t sz;
    char score_string[12];
    FILE *f = fopen(file_name, "w+");

    sprintf(score_string, "%d", score);
    if (!f || !name) {
        printf("Error writing to file %s\n", file_name);
        perror("file");
        return (EXIT_ERROR);
    }
    fwrite(score_string, 1, strlen(score_string), f);
    write(1, "Nouveau record! Entre ton nom: ", 31);
    if (getline(&name, &sz, stdin) == EOF)
        name = strdup("unknown\n");
    else
        printf("hmm... %sun très joli nom.\n", name);
    name[strlen(name) - 1] = 0;
    fwrite(" by ", 1, 4, f);
    fwrite(name, 1, strlen(name), f);
    fwrite("\n", 1, 1, f);
    fclose(f);
    return (0);
}

int save_score(int score, char *file_name)
{
    int fd = open(file_name, O_RDWR|O_CREAT, 0666);
    int best_score;

    if (!file_name || fd == -1) {
        puts("Error: cannot open score file");
        puts(file_name);
        return (EXIT_ERROR);
    }
    best_score = fs_get_number_from_first_line(fd, file_name);
    if (score > best_score)
        write_file(file_name, score);
    close(fd);
    return (0);
}
