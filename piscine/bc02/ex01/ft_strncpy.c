/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:57:13 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 08:57:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	j;

	j = 0;
	while ((src[j] != '\0') && (j < n))
	{
		dest[j] = src[j];
		j++;
	}
	while (dest[j] != '\0')
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "des";
	char	src[] = "source";
	unsigned int	n;

	printf("dest is %s\n", dest);
	printf("sizeof DEST is %lu\n", sizeof(dest));
	ft_strncpy(dest, src, 5);
	printf("dest2 is %s\n", dest);
	printf("sizeof2 DEST is %lu\n", sizeof(dest));
}
*/