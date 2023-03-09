##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

OBJ = $(SRC:.c=.o)

SRC = 	src/my_hunter.c \
		src/main_page.c \
		src/game_page.c \
		src/bar_information.c \
		src/score_registre.c

NAME = my_hunter

LIB = -L ./lib/my/ -lmy

CC = gcc

CFLAGS = -I./include/ -Wall -Wextra -lcsfml-graphics -lcsfml-window

all: $(NAME)

$(NAME): $(SRC)
	make -C lib/my
	gcc $(SRC) -o $(NAME) $(LIB) $(CFLAGS) -lcsfml-system

clean :
	rm -f $(OBJ)
	make clean -C lib/my/

fclean : clean
	make fclean -C lib/my/
	rm -f $(NAME)

re : fclean all
