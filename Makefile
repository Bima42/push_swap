LIBFT_DIR		=	libft/

PUSH_SWAP_SRCS	=	$(addprefix src/, $(SRCS))

SRCS		=	push_swap.c solver.c \
				parsing/push_swap_parsing.c parsing/create_elements.c parsing/parsing_utils.c \
                commands/commands_a.c commands/commands_b.c commands/commands_both.c \
                utils/list_utils.c utils/list_utils_2.c \
				utils/utils_long.c utils/utils_long_2.c

HEAD_PUSH_SWAP	= src/push_swap.h

OBJS_PUSH_SWAP	=	$(addprefix src/, $(SRCS:.c=.o))

CC				= gcc $(CFLAGS)

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -g

NAME			= push_swap

.PHONY:			libft all clean fclean re bonus

all:			$(NAME)

$(NAME):		libft
				$(CC) $(PUSH_SWAP_SRCS) $(HEAD_PUSH_SWAP) $(LIBFT_DIR)libft.a -o $(NAME)
				@echo "Push_swap is ready !"

libft:
				make -C $(LIBFT_DIR) all

clean:
				$(RM) $(OBJS_PUSH_SWAP)
				make -C $(LIBFT_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)
