NAME = libft.a

FLAGS := -Wall -Werror -Wextra
CC := gcc -g
FILES := ft_nbrsize.c ft_all_perms.c ft_atoi.c ft_bzero.c ft_fact.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_issep.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_print_2d.c ft_putchar.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_rotate.c  ft_swapchar.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_max.c ft_isdigit.c ft_issep.c ft_print_len.c ft_abs.c

include string/make.dep
include list/make.dep
include array/make.dep
include gnl/make.dep
include unicode/make.dep

OBJS := $(FILES:%.c=%.o)
INCLUDES := $(addprefix -I, . $(INCLUDES))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(INCLUDES) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
