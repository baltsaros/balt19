#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != 0)
	{
		printf("Content on p[%d] is equal to %d.\n", size, *((int *)lst->content));
		++size;
		lst = lst->next;
	}
	return (size);
}

// int	main(void)
// {
// 	int		*data;
// 	t_list	*head;

// 	if (!(data = (int *)malloc(sizeof(int)*4)))
// 		return (0);
// 	data[0] = 11;
// 	data[1] = 22;
// 	data[2] = 33;
// 	data[3] = 44;
// 	head = ft_lstnew((void *)&data[0]);
// 	head->next = ft_lstnew((void *)&data[1]);
// 	head->next->next = ft_lstnew((void *)&data[2]);
// 	head->next->next->next = ft_lstnew((void *)&data[3]);
// 	printf("Lst size is %d.\n", ft_lstsize(head));
// 	return (0);
// }