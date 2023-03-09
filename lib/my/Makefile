##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

SRC = $(shell find -name '*.c')

OBJ = $(SRC:.c=.o);

NAMELIB = libmy.a

all:	$(NAMELIB)

$(NAMELIB): $(SRC)
	gcc -c $(SRC)
	ar rc $(NAMELIB) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAMELIB)
	make clean

re : fclean all
