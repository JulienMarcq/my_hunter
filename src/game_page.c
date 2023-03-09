/*
** EPITECH PROJECT, 2022
** game page
** File description:
** dsk
*/

#include <hunter.h>
#include <my.h>

void print_anim(window_t *page)
{
    if (sfClock_getElapsedTime(page->clock).microseconds > 150000) {
        page->rectbirdd.left += 207;
        if (page->rectbirdd.left >= 1596)
            page->rectbirdd.left = 0;
        sfSprite_setTextureRect(page->birdd, page->rectbirdd);
        sfClock_restart(page->clock);
    }
}

void touch_bird(window_t *page)
{
    if (page->mouse.y >= page->hauteur && page->mouse.y <= page->hauteur + 205
    && page->mouse.x >= page->i && page->mouse.x <= page->i + 100) {
        if (page->event.type == sfEvtMouseButtonPressed) {
            page->i = 0;
            page->hauteur = page->hauteur + rand() % 650 +1;
            page->speed = page->speed + 0.07;
            page->score = page->score + 1;
        }
        if (page->score > page->max_score)
            page->max_score = page->score;
    }
    if (page->hauteur >= 650)
        page->hauteur = 0;
    sfRenderWindow_display(page->window);
}

void replace_mouse(window_t *page)
{
    sfVector2f poos = {page->mouse.x - 25.5, page->mouse.y - 25.5};
    sfSprite_setPosition(page->cursor, poos);
    sfRenderWindow_drawSprite(page->window, page->cursor, NULL);
}

int print_second(window_t *page)
{
    while (sfRenderWindow_pollEvent(page->window, &page->event)) {
        if (page->event.type == sfEvtClosed)
            sfRenderWindow_close(page->window);
        if (page->event.key.code == sfKeyEscape)
            return 1;
    }
    sfRenderWindow_clear(page->window, sfBlack);
    page->mouse = sfMouse_getPositionRenderWindow(page->window);
    sfRenderWindow_drawSprite(page->window, page->second, NULL);
    replace_mouse(page);
    life_representation(page);
    print_anim(page);
    page->i += page->speed;
    sfVector2f pos = {page->i, page->hauteur};
    if (page->i >= 1000)
        page->i = 0, page->life = page->life + 1;
    sfSprite_setPosition(page->birdd, pos);
    sfRenderWindow_drawSprite(page->window, page->birdd, NULL);
    touch_bird(page);
    return (0);
}

int second_page(window_t *page)
{
    page->rectbirdd = (sfIntRect){0, 0, 205, 205};
    page->birdd = create_anim("src/content/birdd.png",
    (sfVector2f){1, 100}, (sfVector2f){0.6, 0.6}, page);
    page->lifesprite = create_sprite("src/content/life.png",
    (sfVector2f){730, 640}, (sfVector2f){0.5, 0.5});
    page->rectlife = (sfIntRect){0, 0, 440, 0};
    while (sfRenderWindow_isOpen(page->window)) {
        sfRenderWindow_setMouseCursorVisible(page->window, sfFalse);
        if (print_second(page) == 1) {
            sfRenderWindow_setMouseCursorVisible(page->window, sfTrue);
            sfRenderWindow_clear(page->window, sfBlack);
            return 0;
        }
        if (page->life >= 3) {
            sfRenderWindow_setMouseCursorVisible(page->window, sfTrue);
            loose_page(page);
            return 0;
        }
    }
    return 0;
}
