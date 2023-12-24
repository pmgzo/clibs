##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

#carefull with g++ and gcc !

SRCDIR = src/

SRC_SRC	=	append_value.c			\
			str_append.c			\
			create_array_entry.c	\
			create_entry.c			\
			append_value.c			\
			append_entry_helpers.c	\
			append_array.c			\
			append_array_helpers.c	\
			get_next_entry.c		\
			init_json.c				\
			find_helpers.c			\
			find_str_in_array.c		\
			find_obj_in_array.c		\
			find_json_key.c			\
			check_type.c			\
			json_is_valid.c			\
			skip_functions.c		\
			check_marker.c			\
			check_key_value.c		\
			get_key_type.c			\
			get_array.c				\
			get_value.c				\
			get_helpers.c			\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

OBJ	=	$(SRC:.c=.o)

CRITDIR = tests/

CPPFLAGS	+=	-I include/ -D _GNU_SOURCE

CRT_SRC	=	redirect.c			\
		json_checker.test.c		\
		json_append.test.c		\
		json_get.test.c			\

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	libjson.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

test:
	gcc src/main.c $(SRC) $(CPPFLAGS) -g3

tests_run:
	gcc $(SRC) $(CRT) -o unit_tests  $(CPPFLAGS) --coverage -lcriterion
	./unit_tests
	gcovr
	rm -rf *.gcda *.gcno
	rm unit_tests

clean:
	rm -f $(OBJ)
	rm -rf *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

example:
	gcc -c example.c -I include/
	gcc -o example example.o -I include/ -L ./ -ljson

.PHONY: all clean fclean re example
