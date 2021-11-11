/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:54:55 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/21 23:21:37 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Fuction that convert an ascii numbers to an int

static void	fatal_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	count;
	long	res;

	sign = 1;
	count = 0;
	res = 0;
	while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = sign * -1;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		res = res * 10 + nptr[count] - '0';
		count++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		fatal_error();
	return ((int)res);
}
