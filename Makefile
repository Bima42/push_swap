CC			= gcc
FLAGS		= -Wall -Wextra -Werror
LIBFT_PATH 	= ./libft
INCL		= ./src

CFLAGS		= $(FLAGS) -I$(LIBFT_PATH)/ -I$(INCL)/

LINKS		= -L $(LIBFT_PATH) -lft

NAME		= push_swap

SRCS_PATH	= src/

MAIN		= solver.c push_swap.c

CMD			= commands_a.c commands_b.c commands_both.c

UTILS		= list_utils.c list_utils_2.c solver_utils.c utils_long.c utils_long_2.c

PARS		= parsing_utils.c create_elements.c push_swap_parsing.c

SRCS		= $(addprefix $(SRCS_PATH), $(MAIN)) \
				  $(addprefix $(SRCS_PATH)commands/, $(CMD)) \
				  $(addprefix $(SRCS_PATH)utils/, $(UTILS)) \
				  $(addprefix $(SRCS_PATH)parsing/, $(PARS))

OBJS_PSWAP	= $(SRCS:.c=.o)


all:	$(NAME)

$(OBJS_PSWAP): %.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS_PSWAP)
			make -C $(LIBFT_PATH)
			$(CC) -o $(NAME) $(OBJS_PSWAP) $(LINKS)

clean:
		rm -rf $(SRCS:.c=.o)
		make -C $(LIBFT_PATH) clean

fclean:	clean
		rm -rf $(LIBFT_PATH)libft.a
		rm -rf $(NAME)

re:	fclean all

.PHONY : all re clean fclean
