#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void    clear(char **array, int i);
int     *parsing_string(char **argv);
int     *parsing_multi_args(char **argv);
int     *parsing_args(int argc, char **argv);

#endif
