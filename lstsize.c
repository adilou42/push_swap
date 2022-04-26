#include "list.h"

int ft_lstsize(t_list **begin)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *begin;

	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}