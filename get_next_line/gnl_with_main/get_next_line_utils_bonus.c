/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:45:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/02/14 13:04:30 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	unsigned char	*str;
	unsigned char	x;
	size_t			i;

	if (!s)
		return (0);
	str = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == x)
			return (1);
		++i;
	}
	if (str[i] == x)
		return (1);
	return (0);
}

char	*ft_copy(char *unis, char *rest, char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!unis)
		return (0);
	i = 0;
	while (rest[i])
	{
		unis[i] = rest[i];
		++i;
	}
	j = 0;
	while (buf[j])
	{
		unis[i + j] = buf[j];
		++j;
	}
	unis[j + i] = '\0';
	return (unis);
}

char	*ft_strjoin_free(char *rest, char *buf)
{
	char	*unis;

	if (!rest)
	{
		rest = malloc(sizeof(*rest) * 1);
		if (!rest)
			return (0);
		rest[0] = '\0';
	}
	if (!rest || !buf)
	{
		free(rest);
		return (0);
	}
	unis = malloc(sizeof(*unis) * (ft_strlen(rest) + ft_strlen(buf) + 1));
	if (!unis)
		return (0);
	unis = ft_copy(unis, rest, buf);
	free(rest);
	return (unis);
}
