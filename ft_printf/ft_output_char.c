#include "ft_printf.h"

static int	ft_decrease(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

void	ft_output_char(t_par *params, char c, int *r)
{
	if (params->width > 0)
		(*r) += params->width;
	else
		++(*r);
	--params->width;
	while (!params->minus && !params->zero && ft_decrease(&params->width))
		write(1, " ", 1);
	while (params->zero && ft_decrease(&params->width))
		write(1, "0", 1);
	write(1, &c, 1);
	while (params->minus && ft_decrease(&params->width))
		write(1, " ", 1);
}
