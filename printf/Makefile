NAME := libftprintf.a
SRCS := itoas.c parse.c print.c ft_printf.c parser.c utils_printf.c
LIBFT_SRCS := ../libft/libft.a
OBJS := $(SRCS:.c=.o)
INC := $(addprefix -I, ../libft includes)

all: $(NAME)

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS) $(LIBFT_SRCS)
	@ranlib $(NAME)

%.o : %.c
	@gcc -c -g $(INC) $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

