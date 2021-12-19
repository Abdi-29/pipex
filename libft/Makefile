#creating a makefile to run all my programs 

NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	   ft_toupper.c ft_tolower.c ft_strncmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_putstr_fd.c ft_putchar_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_itoa.c \
	   ft_strmapi.c ft_atof.c ft_strcmp.c ft_isspace.c

# COLORS
PINK    = \x1b[35m
BLUE    = \x1b[34m
YELLOW  = \x1b[33m
GREEN   = \x1b[32m
RED     = \x1b[31m
MAGENTA = \x1b[35m

RESET   = \x1b[0m

OBJ = $(SRCS:.c=.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "$(RED)Done $(GREEN)COM$(YELLOW)PI$(BLUE)LING $(PINK)LIBFT$(RESET) :)"

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	@echo "$(RED)COMPILING $(GREEN)PLEASE $(YELLOW)GI$(BLUE)VE $(PINK)IT A MOMENT$(RESET) :)"

clean:
	rm  -f $(OBJ)
	@echo "$(RED)CLEANING $(GREEN)IN $(YELLOW)PROCE$(BLUE)SS $(RESET) :)"

fclean:	clean
	rm -f ${NAME}
	@echo "$(GREEN)ALL CLEANED $(RESET) :)"
	
re: @fclean all

.PHONY: @all clean fclean re
