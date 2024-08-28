NAME = philo
CFLAGS = -Werror -Wall -Wextra -pthread -g
RM = rm -rf
OBJ_DIR = obj
SRCS = philo.c \
	   lib/ft_atoi.c \
	   valid_args/valid_args.c \
	   saves_init/saves_init.c \
	   lets_start_dinner/lets_start_dinner.c \
	   lets_start_dinner/create_routines.c 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
YELLOW = \033[38;2;249;226;175m
BLUE = \033[38;2;180;190;254m
GREEN = \033[38;2;166;227;161m
RESET = \033[38;2;205;214;244m

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@cc $(CFLAGS) -c $< -o $@
	@sleep 0.1
	@printf "\r${YELLOW}[ ]${RESET} compiling ${BLUE}$<"

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\r${GREEN}[✔]${RESET} compiled successfully! ${BLUE}.  ★                    \n"

all: $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@printf "\n${GREEN}[✔]${RESET} rm name successfully! ${BLUE}✧̣̇ ˳\n"

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@printf "\r${GREEN}[✔]${RESET} rm objs successfully! ${BLUE}.˚ ✦"

re: fclean all
