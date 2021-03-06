/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:07:45 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/10 17:12:19 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_3(t_list **begin)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f = *begin;
	s = (*begin)->next;
	t = (*begin)->next->next;
	if ((f->v > s->v) && (s->v > t->v) && (t->v < f->v))
	{
		ft_rotate(begin, 1);
		ft_swap(begin, 1);
	}
	else if ((f->v > s->v) && (s->v < t->v) && (t->v < f->v))
		ft_rotate(begin, 1);
	else if ((f->v > s->v) && (s->v < t->v) && (t->v > f->v))
		ft_swap(begin, 1);
	else if ((f->v < s->v) && (s->v > t->v) && (t->v < f->v))
		ft_reverse_rotate(begin, 1);
	else if ((f->v < s->v) && (s->v > t->v) && (t->v > f->v))
	{
		ft_reverse_rotate(begin, 1);
		ft_swap(begin, 1);
	}
}

void	ft_small_sort(t_list **begin_a, t_list **begin_b)
{
	int	size;

	size = ft_lstsize(begin_a);
	if ((ft_is_sorted(begin_a) == 0) && size == 2)
	{
		ft_swap(begin_a, 1);
	}
	else if ((ft_is_sorted(begin_a) == 0) && size == 3)
	{
		ft_sort_3(begin_a);
	}
	else if ((ft_is_sorted(begin_a) == 0) && size == 4)
	{
		ft_sort_4(begin_a, begin_b);
	}
	else if ((ft_is_sorted(begin_a) == 0) && size == 5)
	{
		ft_sort_5(begin_a, begin_b);
	}
}
