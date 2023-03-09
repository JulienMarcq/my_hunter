/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** dsk
*/

#include "hunter.h"
#include "my.h"

int max_score(window_t *page)
{
    sfText *test;
    sfVector2f haut = {600, 300};
    sfVector2f a = {870, 300};
    test = sfText_create();
    sfText_setFont(test, page->myfont);
    sfText_setCharacterSize(test, 50);
    sfText_setPosition(test, haut);
    sfText_setColor(test, sfBlack);
    sfText_setString(test, "Max Score:");
    sfRenderWindow_drawText(page->window, test, NULL);
    sfText_setPosition(test, a);
    write_max(page);
    sfText_setString(test, my_itoa(read_max()));
    sfRenderWindow_drawText(page->window, test, NULL);
    return (0);
}

sfSprite *create_anim(char *path, sfVector2f p, sfVector2f s, window_t *page)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, page->rectbirdd);
    sfSprite_setPosition(sprite, p);
    sfSprite_setScale(sprite, s);
    return (sprite);
}

sfSprite *create_sprite(char *path, sfVector2f p, sfVector2f s)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, p);
    sfSprite_setScale(sprite, s);
    return (sprite);
}

int info(int ac, char **av)
{
    if (ac != 2) {
        write(1, "error\n", 7);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        if (av[1][2] != '\0') {
            write(1, "error\n", 7);
            return (84);
        }
        write(1, "USAGE\n", 7);
        write(1, "    ./my_hunter\n", 17);
        write(1, "DESCRIPTION\n", 13);
        write(1, "    The goal of the game is to shoot as many birds", 51);
        write(1, "as possible.\n    You have 3 lives\n", 35);
        return (0);
    } else {
        write(1, "error\n", 7);
        return (84);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL) {
        write(1, "error env\n", 11);
        return (84);
    }
    if (ac > 1)
        return (info (ac, av));
    window_t page;
    page.video_mode.width = 1000;
    page.video_mode.height = 750;
    page.video_mode.bitsPerPixel = 32;
    page.window = sfRenderWindow_create(page.video_mode,
    "My Hunter", sfResize | sfClose, NULL);
    if (!page.window)
        return (84);
    initialisation(&page);
    main_page(&page);
    return 0;
}
