#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == c)
			return (void *)s + i;
		++i;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char buffer[] = "h\0ello world!";
// 	int		c;
// 	char	*ret;
// 	const char buffer2[] = "h\0ello world!";
// 	char	*ret2;

// 	c = 'e';
// 	ret = ft_memchr(buffer, c, 6);
// 	if (NULL == ret)
// 		printf("C was not found. Ret(ft) is '%s'\n", ret);
// 	else
// 		printf("C was found. Ret(ft) is '%s'\n", ret);
// 	ret2 = memchr(buffer2, c, 6);
// 	if (NULL == ret2)
// 		printf("C was not found. Ret(or) is '%s'\n", ret2);
// 	else
// 		printf("C was found. Ret(or) is '%s'\n", ret2);
// 	return (0);
// }