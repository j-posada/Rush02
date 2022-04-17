CC				:= gcc
RM				:= rm -f
DEFAULT_CFLAGS	:= -Wall -Wextra -Werror
NAME			:= rush-02
SRC				:= $(*.c)
OBJ				:= $(SRC:.c=.o)
.PHONY			: all clean fclean re

$(NAME): $(OBJ)
	$(CC) -o $@ $^

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(DEFAULT_CFLAGS) $(CFLAGS) -o $@ -c $<

norm:
	norminette -R CheckForbiddenSourceHeader
