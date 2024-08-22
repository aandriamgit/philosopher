NAME = philo

CFLAGS = -Werror -Wall -Wextra -g

RM = rm -rf

SRCS = philo.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all
