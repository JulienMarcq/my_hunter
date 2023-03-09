/*
** EPITECH PROJECT, 2022
** main_page
** File description:
** dsk
*/

#include <hunter.h>
#include <my.h>

void print_anime(window_t *page)
{
    if (sfClock_getElapsedTime(page->clock).microseconds > 200000) {
        page->rect.left += 35;
        page->rectcerf.left += 32;
        if (page->rect.left >= 70)
            page->rect.left = 0;
        if (page->rectcerf.left >= 160)
            page->rectcerf.left = 0;
        sfSprite_setTextureRect(page->cerf, page->rectcerf);
        sfSprite_setTextureRect(page->eau1, page->rect);
        sfSprite_setTextureRect(page->eau2, page->rect);
        sfSprite_setTextureRect(page->eau3, page->rect);
        sfClock_restart(page->clock);
    }
}

int bouton(window_t *page)
{
    if (page->mouse.x >= 106 && page->mouse.x <= 394 && page->mouse.y >= 200
    && page->mouse.y <= 249) {
        sfRenderWindow_drawSprite(page->window, page->start2, NULL);
        if (page->event.type == sfEvtMouseButtonPressed) {
            second_page(page);
            return (0);
        }
    }
    sfRenderWindow_drawSprite(page->window, page->quit, NULL);
    if (page->mouse.x >= 107 && page->mouse.x <= 399 && page->mouse.y >= 399
    && page->mouse.y <= 452) {
        sfRenderWindow_drawSprite(page->window, page->quit2, NULL);
        if (page->event.type == sfEvtMouseButtonPressed){
            sfRenderWindow_close(page->window);
            return (0);
        }
    }
    return (0);
}

int print(window_t *page)
{
    while (sfRenderWindow_pollEvent(page->window, &page->event)) {
        if (page->event.type == sfEvtClosed) {
            sfRenderWindow_close(page->window);
        }
    }
    sfRenderWindow_clear(page->window, sfBlack);
    page->mouse = sfMouse_getPositionRenderWindow(page->window);
    sfRenderWindow_drawSprite(page->window, page->fond, NULL);
    sfRenderWindow_drawSprite(page->window, page->eau1, NULL);
    sfRenderWindow_drawSprite(page->window, page->eau2, NULL);
    sfRenderWindow_drawSprite(page->window, page->eau3, NULL);
    sfRenderWindow_drawSprite(page->window, page->cerf, NULL);
    sfRenderWindow_drawSprite(page->window, page->start, NULL);
    sfRenderWindow_drawSprite(page->window, page->logo, NULL);
    print_anime(page);
    bouton(page);
    sfRenderWindow_display(page->window);
    return 0;
}

void part_second(window_t *page)
{
    page->fond = create_sprite("src/content/main_page.png",
    (sfVector2f){0, 0}, (sfVector2f){0.52, 0.52});
    page->logo = create_sprite("src/content/logo.png",
    (sfVector2f){560, 150}, (sfVector2f){0.85, 0.85});
    page->rect = (sfIntRect){0, 0, 35, 700};
    page->eau2 = create_anim("src/content/pixil-frame-0.png",
    (sfVector2f){785, 174}, (sfVector2f){0.55, 0.72}, page);
    page->rect = (sfIntRect){0, 0, 35, 700};
    page->eau3 = create_anim("src/content/pixil-frame-1.png",
    (sfVector2f){521, 100}, (sfVector2f){0.55, 0.54}, page);
    page->second = create_sprite("src/content/second_page.png",
    (sfVector2f){0, -500}, (sfVector2f){0.75, 0.75});
    page->cursor = create_sprite("src/content/cursor.png",
    (sfVector2f){0, 0}, (sfVector2f){0.1, 0.1});
}

int main_page(window_t *page)
{
    page->start = create_sprite("src/content/start_bouton.png",
    (sfVector2f){70, 180}, (sfVector2f){0.7, 0.7});
    page->start2 = create_sprite("src/content/start_bouton2.png",
    (sfVector2f){70, 180}, (sfVector2f){0.7, 0.7});
    page->quit = create_sprite("src/content/quit_bouton.png",
    (sfVector2f){70, 380}, (sfVector2f){0.7, 0.7});
    page->quit2 = create_sprite("src/content/quit_bouton2.png",
    (sfVector2f){70, 380}, (sfVector2f){0.7, 0.7});
    page->rect = (sfIntRect){0, 0, 35, 700};
    page->eau1 = create_anim("src/content/pixil-frame-0.png",
    (sfVector2f){952, 120}, (sfVector2f){0.55, 0.65}, page);
    page->rectcerf = (sfIntRect){0, 0, 33, 50};
    page->cerf = create_anim("src/content/cerf.png",
    (sfVector2f){460, 650}, (sfVector2f){1.5, 1.5}, page);
    part_second(page);
    while (sfRenderWindow_isOpen(page->window))
        print(page);
    sfRenderWindow_destroy(page->window);
    return (0);
}
