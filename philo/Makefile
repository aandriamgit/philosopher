NAME = philo
CFLAGS = -Werror -Wall -Wextra -pthread -g
RM = rm -rf
OBJ_DIR = obj
SRCS = philo.c\
	   lib/ft_atoi.c \
	   valid_args/valid_args.c \
	   saves_init/saves_init.c 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all
