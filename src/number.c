/*
** ARTHUR MASSANES PROJECT, 2019
** snake
** File description:
** number func
*/

#include "snake.h"

int is_num(char c)
{
    if (c <= '9' && c >= '0')
        return (1);
    else
        return (0);
}

int fs_get_number_len(int fd)
{
    char buff[2] = "0\0";
    int num_size = 0;
    int rd = 1;

    if (fd == -1)
        return (-1);
    while (is_num(buff[0]) && rd > 0) {
        rd = read(fd, buff, 1);
        buff[1] = 0;
        num_size += rd;
    }
    return (num_size - 1);
}

int get_nbr(char *str)
{
    int i = 0;
    int nbr = 0;

    if (!str[i] || strlen(str) < 1)
        return (0);
    while (is_num(str[i])) {
        nbr += str[i] - 48;
        nbr *= 10;
        i++;
    }
    return (nbr / 10);
}

int fs_get_number_from_first_line(int fd, char *file_name)
{
    char *buff;
    int len = fs_get_number_len(fd);
    int nbr;
    int fd_dup = open(file_name, O_RDONLY);
    int rd;

    buff = malloc(sizeof(char) * len + 1);
    if (!buff || fd_dup == -1 || len < 0)
        return (-1);
    else if (fd == -1) {
        puts("Error: Cannot get previous best score");
        return (-1);
    }
    rd = read(fd_dup, buff, len);
    buff[rd] = 0;
    close(fd_dup);
    close(fd);
    nbr = get_nbr(buff);
    free(buff);
    return (nbr == 0 ? -1 : nbr);
}
