/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:42:49 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:43:15 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_loop_ls(t_list **begin_a, int min, int i)
{
	t_list	*a;

	a = *begin_a;
	i = 0;
	while (a && a->value != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_last_sort(t_list **begin_a, int min)
{
	t_list		*a;
	int			i;
	int			j;

	a = *begin_a;
	i = 0;
	i = ft_loop_ls(&a, min, i);
	j = ft_lstsize(begin_a) - i;
	if (i < j)
	{
		while (i)
		{
			ft_rotate(begin_a);
			i--;
		}
	}
	else
	{
		while (j)
		{
			ft_reverse_rotate(begin_a);
			j--;
		}
	}
}
