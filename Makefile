SFILES      = main.c split.c str_join.c
OFILES      = $(SFILES:.c=.o)
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror -I. -g3# -fsanitize=leak,address

NAME        = pipex

$(NAME):    $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

all:        $(NAME)

clean:
	$(RM) $(OFILES)

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
