#include <stdlib.h>
int		ft_totallen(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		length;

	j = 0;
	length = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			++length;
			++i;
		}
		++j;
	}
	i = 0;
	while (sep[i])
		++i;
	return (length + i * (size - 1));
}

void	ft_concatenation(int size, char *unistr, char **strs, char *sep)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			*unistr = strs[j][i];
			++unistr;
			++i;
		}
		if (j < size - 1)
			ft_addsep(&unistr, sep);
		j++;
	}
	*unistr = '\0';
}

void	ft_addsep(char **unistr, char *sep)
{
	int		s;

	s = 0;
	while (sep[s])
	{
		**unistr = sep[s];
		++*unistr;
		++s;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*unistr;
	char	*str_ret;

	length = ft_totallen(size, strs, sep);
	str_ret = (char *)malloc(sizeof(*str_ret) * (length + 1));	
	unistr = str_ret;
	ft_concatenation(size, unistr, strs, sep);
	return (str_ret);
}

#include <stdio.h>
int		main(void)
{
	char	*strs[5];

	strs[0] = "hello";
	strs[1] = "there";
	strs[2] = "you";
	strs[3] = "look";
	strs[4] = "great";
	printf("%s\n", ft_strjoin(5, strs, "!"));
	return (0);
}