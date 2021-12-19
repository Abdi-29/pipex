NAME = pipex

SRC = 	pipex.c \
		process.c
INCLUDE = -I ./includes
OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

# COLORS
PINK    = \x1b[35m
BLUE    = \x1b[34m
YELLOW  = \x1b[33m
GREEN   = \x1b[32m
RED     = \x1b[31m
MAGENTA = \x1b[35m

RESET   = \x1b[0m

FLAGS = -Wall -Werror -Wextra
DEBUG = -g 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(LIBFT) $(DEBUG) $(FLAGS) -o $(NAME) 

%.o: %.c
	gcc -c $(INCLUDE) $(DEBUG) $(FLAGS) $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)


clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
