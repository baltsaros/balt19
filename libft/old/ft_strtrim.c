#include "libft.h"

size_t	ft_strlen(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static size_t	check_set(int ch, char const *set)
{
	size_t	i;

	i = 0;
	while(set[i])
	{
		if (ch == set[i])
			return (1);
		++i;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_ch;
	char	*dest_ch;
	
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	i = 0;
	while (n > i && src_ch[i])
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (NULL == s1)
		return (NULL);
	if (NULL == set)
		return (char *)s1;
	while (check_set(s1[i], set))
		++i;
	start = i;
	i = ft_strlen(s1) - 1;
	while(check_set(s1[i], set))
		--i;
	end = i + 1;
	if (start >= end)
		return (NULL);
	tr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) - end + 2));
	if (NULL == tr)
		return (NULL);
	ft_memcpy(tr, s1 + start, (end - start));
	tr[end - start] = '\0';
	return (tr);
}

int		main(void)
{
	printf("input | correct answer | ft result\n");
	printf("TESTa - a| TEST | %s\n", ft_strtrim("TESTa", "a"));
	printf("TESTabc - abc| TEST | %s\n", ft_strtrim("TESTabc", "abc"));
	printf("abcTEST - abc| TEST | %s\n", ft_strtrim("abcTEST", "abc"));
	printf("abcTESTabc - abc | TEST | %s\n", ft_strtrim("abcTESTabc", "abc"));
	printf("abcTabc - abc | T | %s\n", ft_strtrim("abcTabc", "abc"));
	printf("TEST - abc | TEST | %s\n", ft_strtrim("TEST", "abc"));
	printf("abcTEST - bca | TEST | %s\n", ft_strtrim("abcTEST", "bca"));
	printf("abcTEabcSTcab - bca | TEabcST | %s\n", ft_strtrim("abcTEabcSTcab", "bca"));
	printf("aaaaaaTESTbbbbbb - abc | TEST | %s\n", ft_strtrim("aaaaaaTESTbbbbbb", "abc"));
	printf("aaaaaaTESTbbbbbbccccccc - abc | TEST | %s\n", ft_strtrim("aaaaaaTESTbbbbbbccccccc", "abc"));
	printf("bcaTESTcab - | bcaTESTcab | %s\n", ft_strtrim("bcaTESTcab", ""));
	printf("  bcaTESTcab   -    | bcaTESTcab | %s\n", ft_strtrim("  bcaTESTcab  ", "  "));
	printf("abcTEST - l | abcTEST | %s\n", ft_strtrim("abcTEST", "l"));
	printf("abcTEST - 10 | abcTEST | %s\n", ft_strtrim("abcTEST", "10"));
	printf("abcTEST10 - 10 | abcTEST | %s\n", ft_strtrim("abcTEST10", "10"));
	printf("abccba - bca | (null) | %s\n", ft_strtrim("abccba", "bac"));
	printf(" - abc | (null) | %s\n", ft_strtrim("", "abc"));
	printf("NULL - abc| (null) | %s\n", ft_strtrim(NULL, "abc"));
	printf("abc - NULL | abc | %s\n", ft_strtrim("abc", NULL));
	printf("NULL - NULL | (null) | %s\n", ft_strtrim(NULL, NULL));
	return (0);
}