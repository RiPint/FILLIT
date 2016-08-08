
NAME	=	libft.a

SRCS	=	ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putaddr.c \
			ft_putaddr_fd.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_isascii.c \
			ft_iswhitespace.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strclr.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_striter.c \
			ft_striteri.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_lstnew.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstqueue.c \
			ft_strtoupcase.c \
			ft_strtodowncase.c \
			ft_strcapitalize.c \
			ft_btree_create_node.c \
			ft_btree_apply_prefix.c \
			ft_btree_apply_suffix.c \
			ft_btree_apply_infix.c \
			ft_btree_insert_data.c \
			ft_btree_search_item.c \
			ft_btree_level_count.c \
			get_next_line.c

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

AR		=	ar

RANLIB	=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

CLEAN	=	clean

.PHONY	:	re clean fclean all

all		:
		@make $(NAME)

$(NAME)	:	$(OBJS)
		@echo "\033[1m\033[34mMaking library.\033[0m"
		@$(AR) rc $@ $^
		@echo "\033[1m\033[34mCreate table of contents.\033[0m"
		@$(RANLIB) $@
		@echo "\033[1m\033[32mCompilation done !!\033[0m\n"

%.o		:	%.c
		@echo "\033[1m\033[31mBuilding\033[0m \t$<"
		@$(CC) $(CFLAGS) -o $@ -c $^ -I ./include

clean	:
		@$(RM) $(OBJS)
		@echo "\033[31m*.o files deleted.\033[0m"

fclean	:	clean
		@$(RM) $(NAME)
		@echo "\033[31mLibrary file deleted.\033[0m"

re		:	fclean all
