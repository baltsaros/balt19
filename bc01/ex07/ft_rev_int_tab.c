/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 08:13:25 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/10 08:13:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int		tab2;
	int		i;

	tab2[size];
	i = 0;
	while (size != 0)
	{
		tab2[i] = tab[size - 1];
		i++;
		size--;
	}
}

/*
int		main()
{
	int		tab[] = { 1, 2, 3, 4, 5 };

	ft_rev_int_tab(tab, 5);
	printf("%d ", tab2[i]);
}
*/