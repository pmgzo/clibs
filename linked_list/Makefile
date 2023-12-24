SRCDIR	=	src/

SRC_SRC	=		rotate_linked_list.c	\
				add_element.c			\
				swap_element.c			\
				insert_element.c		\
				list_to_array.c			\
				remove_element.c		\
				return_size.c			\
				filter_list.c			\

SRC		=	$(addprefix $(SRCDIR), $(SRC_SRC))

OBJ		= 	$(SRC:.c=.o)

NAME		=	liblinkedlist.a

CFLAGS        +=      -I include

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f example

fclean: clean
	rm -f $(NAME)

re:	fclean	all

example:
	gcc -c example.c -I ./include
	gcc -o example example.o -L ./ -llinkedlist -I ./include

.PHONY: all clean fclean re example
