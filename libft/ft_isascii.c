#include <stdio.h>

int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isascii('ç');
	printf("return is %d\n", ret);
	return (0);
}
