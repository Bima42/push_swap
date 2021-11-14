LIBFT_DIR		=	libft/

PUSH_SWAP_SRCS	=	$(addprefix src/, $(SRCS))

SRCS		=	push_swap.c push_swap_parsing.c create_elements.c \
                commands_a.c commands_b.c commands_both.c solver.c \
                parsing_utils.c solver_utils.c solver_utils_2.c solver_utils_3.c \
				solver_utils_4.c solver_long_utils.c

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
