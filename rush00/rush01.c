/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:36:47 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/12 13:36:50 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_firstline(int x)
{
	int		i;

	i = 1;
	ft_putchar('/');
	while (++i != x)
	{
		ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	ft_halfline(int x)
{
	int		i;

	ft_putchar('*');
	i = 1;
	while (x > ++i)
	{
		ft_putchar(' ');
	}
	ft_putchar('*');
	ft_putchar('\n');
}

void	ft_lastline(int x)
{
	int		i;

	i = 1;
	ft_putchar('\\');
	while (++i != x)
	{
		ft_putchar('*');
	}
	ft_putchar('/');
	ft_putchar('\n');
}

void	ft_firstcolumn(int y)
{
	int		i;

	i = 1;
	ft_putchar('/');
	ft_putchar('\n');
	while (++i != y)
	{
		ft_putchar('*');
		ft_putchar('\n');
	}
	ft_putchar('\\');
	t_putchar('\n');
}

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{
		ft_putchar('/');
		ft_putchar('\n');
	}
	else if (x > 1 && y == 1)
	{
		ft_firstline(x);
	}
	else if (x == 1 && y > 1)
	{
		ft_firstcolumn(y);
	}
	else
	{
		ft_firstline(x);
		while (--y > 1)
		{
			ft_halfline(x);
		}
		ft_lastline(x);
	}
}
