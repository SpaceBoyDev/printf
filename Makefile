NAME = libftprintf.a

CC = cc

AR = ar

ARFLAGS = -rc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = \
	main.c \
	ft_printf.c

#BONUS =

OBJS = $(SRCS:.c=.o)

#BNS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) -o $(NAME) $(OBJS)

#bonus: $(BNS)
#	$(AR) $(ARFLAGS) $(NAME) $(BNS)

cc: $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
