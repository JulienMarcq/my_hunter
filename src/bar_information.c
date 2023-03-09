/*
** EPITECH PROJECT, 2022
** info
** File description:
** dsk
*/

#include "hunter.h"
#include "my.h"

int final_score(window_t *page)
{
    sfText *test;
    sfVector2f pos = (sfVector2f){650, 230};
    sfVector2f a = (sfVector2f){820, 230};
    test = sfText_create();
    sfText_setFont(test, page->myfont);
    sfText_setCharacterSize(test, 50);
    sfText_setPosition(test, pos);
    sfText_setColor(test, sfBlack);
    sfText_setString(test, "Score:");
    sfRenderWindow_drawText(page->window, test, NULL);
    sfText_setPosition(test, a);
    sfText_setString(test, my_itoa(page->score));
    sfRenderWindow_drawText(page->window, test, NULL);
    max_score(page);
    return 0;
}

int score (window_t *page)
{
    sfText *test;
    sfVector2f pos = (sfVector2f){150, 630};
    sfVector2f a = (sfVector2f){320, 630};
    test = sfText_create();
    sfText_setFont(test, page->myfont);
    sfText_setCharacterSize(test, 50);
    sfText_setPosition(test, pos);
    sfText_setColor(test, sfBlack);
    sfText_setString(test, "Score:");
    sfRenderWindow_drawText(page->window, test, NULL);
    sfText_setPosition(test, a);
    sfText_setString(test, my_itoa(page->score));
    sfRenderWindow_drawText(page->window, test, NULL);
    return 0;
}

int life_representation(window_t *page)
{
    if (page->life == 3) {
        page->rectlife.top = 372;
        page->rectlife.height = 0;
    }
    if (page->life == 2) {
        page->rectlife.top = 249;
        page->rectlife.height = 123;
    }
    if (page->life == 1) {
        page->rectlife.top = 124;
        page->rectlife.height = 125;
    }
    if (page->life == 0) {
        page->rectlife.top = 0;
        page->rectlife.height = 124;
    }
    sfSprite_setTextureRect(page->lifesprite, page->rectlife);
    sfRenderWindow_drawSprite(page->window, page->lifesprite, NULL);
    score(page);
    return 0;
}

int score_loose(window_t *page)
{
    sfRenderWindow_clear(page->window, sfBlack);
    sfRenderWindow_drawSprite(page->window, page->second, NULL);
    final_score(page);
    sfRenderWindow_drawSprite(page->window, page->loose, NULL);
    sfSprite_setPosition(page->lifesprite, (sfVector2f){630, 400});
    sfRenderWindow_drawSprite(page->window, page->lifesprite, NULL);
    sfRenderWindow_display(page->window);
    while (sfRenderWindow_pollEvent(page->window, &page->event)) {
        if (page->event.type == sfEvtClosed)
            sfRenderWindow_close(page->window);
        if (page->event.key.code == sfKeyEscape) {
            page->score = 0;
            page->life = 0;
            page->speed = 0.2, page->i = 0;
            sfRenderWindow_clear (page->window, sfBlack);
            print(page);
            return 1;
        }
    }
    return 0;
}

int loose_page(window_t *page)
{
    page->pos = (sfVector2f){0, 50};
    page->scale = (sfVector2f){0.5, 0.5};
    page->loose_texture = sfTexture_createFromFile("src/content/loose.png",
    NULL);
    page->loose = sfSprite_create();
    page->rectlife.top = 372;
    page->rectlife.height = 496;
    sfSprite_setTexture(page->loose, page->loose_texture, sfTrue);
    sfSprite_setPosition(page->loose, page->pos);
    sfSprite_setScale(page->loose, page->scale);
    sfSprite_setTextureRect(page->lifesprite, page->rectlife);
    while (sfRenderWindow_isOpen(page->window)) {
        if (score_loose(page) == 1)
            return 0;
    }
    return 0;
}
