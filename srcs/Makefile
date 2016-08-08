NAME		=	fillit

SRCS		=	srcs/ft_check_error.c \
				srcs/ft_check_len.c \
				srcs/ft_fillit_algo.c \
				srcs/ft_is_all.c \
				srcs/ft_is_all_second.c \
				srcs/ft_putab.c \
				srcs/ft_resize.c \
				srcs/ft_resolve_toolbox.c \
				srcs/ft_tablen.c \
				srcs/ft_tetra_toolbox.c \
				srcs/ft_tetrabox.c \
				srcs/main.c

SRCDIR		=	srcs

INCDIR		=	include

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

LIBDIR		=	libft

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

CLEAN		=	clean

.PHONY		:	re clean fclean libft all

.SILENT		:	all

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJS)
				@echo "\033[1m\033[34mCreating executable.\033[0m"
				@$(CC) $(CFLAGS) $^ -I $(INCDIR) -o $(NAME)
				@echo "\033[1m\033[32mCompilation done !!\033[0m\n"

$(LIBFT)	:
				@make -C $(LIBDIR)

libcl		:
				@make -C $(LIBDIR) fclean

%.o			:	%.c
				@echo "\033[1m\033[31mBuilding\033[0m \t$<"
				@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)/

clean		:	libcl
				@$(RM) $(OBJS)
				@echo "\033[31m*.o files deleted.\033[0m"

fclean		:	clean
				@$(RM) $(NAME)
				@echo "\033[31mExecutable file deleted.\033[0m"

re			:	fclean libcl all
