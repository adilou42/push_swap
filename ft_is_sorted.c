#include "list.h"

int ft_is_sorted(t_list **begin)
{
	t_list *tmp;

	tmp = *begin;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x && tmp->next)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}