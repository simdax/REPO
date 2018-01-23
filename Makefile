NAME = ft_ls
LD = libft/libft.a printf/libftprintf.a
INC = $(addprefix -I, . libft libft/list printf/includes)
FLAGS = $(INC) -g -Wall -Werror -Wextra
MAIN = main.c utils.c mklist.c process.c list_utils.c
PRINT = $(addprefix padding/, main.c utils.c colors.c print.c)
SRCS = $(MAIN) $(PRINT)
OBJS = $(SRCS:%.c=objs/%.o)

vpath %.c srcs

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C printf
	gcc $(FLAGS) -lm -lncurses $(LD) $^ -o $(NAME)

objs/%.o:%.c ft_ls.h
	@mkdir -p $(dir $@)
	gcc $(FLAGS) $(INC) -c $< -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all
