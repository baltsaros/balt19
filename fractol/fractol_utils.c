/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:54:27 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/29 13:37:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	encode_rgb(int i, int iter, int *setting)
{
	if (setting[1] == 1)
		return (((1433 + i) % 250) << 16 | (190 - i) << 8 | 80 * (i < iter));
	else if (setting[1] == 2)
		return (((1499 + i) % 256) << 16 | (155 - i) << 8 | 200 * (i < iter));
	else if (setting[1] == 3)
		return (((133 + i) % 150) << 16 | (235 - i) << 8 | 170 * (i < iter));
	else
		exit(EXIT_FAILURE);
}

int	ft_mini_atoi(const char *str)
{
	int	n;

	n = 0;
	if (str[0] < 49 || str[0] > 51)
		return (-1);
	if (str[1])
		return (-1);
	n = n * 10 + str[0] - '0';
	return (n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
		++i;
	return (str1[i] - str2[i]);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = img ->bpp - 8;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
	while (i >= 0)
	{
		if (img->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
