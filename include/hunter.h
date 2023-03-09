/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** dsk
*/

#ifndef HUNTER_H_
    #define HUNTER_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdio.h>

    typedef struct window_s {
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
        sfClock *clock;
        sfSprite *fond;
        sfSprite *start;
        sfSprite *start2;
        sfSprite *quit;
        sfSprite *quit2;
        sfSprite *eau1;
        sfSprite *eau2;
        sfSprite *eau3;
        sfSprite *cerf;
        sfSprite *logo;
        sfIntRect rectcerf;
        sfIntRect rect;
        sfSprite *second;
        sfSprite *birdd;
        sfSprite *cursor;
        sfSprite *lifesprite;
        sfIntRect rectbirdd;
        sfIntRect rectlife;
        sfVector2i mouse;
        sfSprite *loose;
        sfTexture *loose_texture;
        sfVector2f pos;
        sfVector2f scale;
        sfFont *myfont;

        double i;
        double speed;
        int hauteur;
        int score;
        int life;
        int max_score;
        int read_score;
    } window_t;

    int write_max(window_t *page);
    sfSprite *create_anim(char *path, sfVector2f p, sfVector2f s,
    window_t *page);
    sfSprite *create_sprite(char *path, sfVector2f p, sfVector2f s);
    int life_representation(window_t *page);
    int print(window_t *page);
    int main_page(window_t *page);
    int second_page(window_t *page);
    int loose_page(window_t *page);
    int max_score(window_t *page);
    int read_max(void);
    int initialisation(window_t *page);

#endif /* !HUNTER_H_ */
