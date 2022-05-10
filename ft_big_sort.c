/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:43:32 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/10 17:13:24 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_push_sup_med(t_list **begin_a, t_list **begin_b, int med)
{
	t_list		*tmp_a;
	t_list		*tmp_b;
	int			min;
	int			max;

	tmp_a = *begin_a;
	tmp_b = *begin_b;
	min = ft_get_min(&tmp_a);
	max = ft_get_max(&tmp_a);
	if ((tmp_a->v != med) && (tmp_a->v != min) && (tmp_a->v != max))
		ft_push(&tmp_a, &tmp_b, 2);
	else
		ft_rotate(&tmp_a, 1);
	*begin_a = tmp_a;
	*begin_b = tmp_b;
}

void	ft_index(t_list **begin)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *begin;
	while (tmp1)
	{
		tmp2 = *begin;
		while (tmp2)
		{
			if (tmp2->v < tmp1->v)
				tmp1->count++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	ft_recup_mediane(t_list **begin_a)
{
	t_list		*tmp;
	int			med_index;
	int			med_v;

	tmp = *begin_a;
	med_v = 0;
	ft_index(begin_a);
	if (ft_lstsize(begin_a) % 2 == 0)
		med_index = ft_lstsize(begin_a) / 2;
	else
		med_index = ft_lstsize(begin_a) / 2 + 1;
	while (tmp)
	{
		if (tmp->count == med_index)
			med_v = tmp->v;
		tmp = tmp->next;
	}
	return (med_v);
}

void	ft_big_sort(t_list **begin_a, t_list **begin_b)
{
	int	med;
	int	size;
	int	tmp1;

	tmp1 = 0;
	size = ft_lstsize(begin_a);
	med = ft_recup_mediane(begin_a);
	while (tmp1 < size)
	{
		ft_push_sup_med(begin_a, begin_b, med);
		tmp1++;
	}
	ft_sort_3(begin_a);
	ft_btoa(begin_a, begin_b);
}
