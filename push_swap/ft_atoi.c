/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:28:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 17:56:26 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_i(int *i, int *sign, const char *str)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		++*i;
	if (str[*i] == '-' || str[*i] == '+')
	{
		*sign = 1 - 2 * (str[*i] == '-');
		++*i;
	}
}

int	ft_atoi(const char *str, int *error)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	ft_check_i(&i, &sign, str);
	if (str[i] < 48 || str[i] > 57)
		*error = 1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		++i;
		if ((n > INT_MAX && sign > 0) || (n > (long)INT_MAX + 1 && sign < 0))
			*error = 1;
	}
	return (sign * n);
}
