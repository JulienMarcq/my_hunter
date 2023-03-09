/*
** EPITECH PROJECT, 2022
** score
** File description:
** dsk
*/

#include "my.h"
#include "hunter.h"

int read_max(void)
{
    int fd = open("src/max_score.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    int score = 0;
    read(fd, buffer, 1000);
    score = my_getnbr(buffer);
    free(buffer);
    return score;
}

int wr_max(window_t *page)
{
    int fd;
    fd = open("src/max_score.txt", O_WRONLY);
    write(fd, my_itoa(page->score), my_strlen(my_itoa(page->score)));
    close(fd);
    return 0;
}

int write_max(window_t *page)
{
    int fd = open("src/max_score.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 1000);
    read(fd, buffer, 1000);
    if (page->max_score > my_getnbr(buffer)) {
        wr_max(page);
    }
    free(buffer);
    return 0;
}

int initialisation(window_t *page)
{
    page->myfont = sfFont_createFromFile("src/content/arial.ttf");
    page->clock = sfClock_create();
    page->life = 0;
    page->score = 0;
    page->i = 1;
    page->speed = 0.2;
    page->hauteur = 30;
    page->max_score = 0;
    return 0;
}
