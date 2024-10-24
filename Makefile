NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC_PATH = srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH = objects/
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
SRCS_OBJ = $(SRCS:.c=.o)
SRC = main.c split.c utils.c another_stack_thingy.c little_joke.c radicks.c short_sort.c some_thingies.c stackops.c\
		they_see_me_rollin.c

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
