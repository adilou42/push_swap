#include "list.h"

void ft_lstclear(t_list **begin)
{
	t_list *tmp;

	tmp = *begin;
	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
}