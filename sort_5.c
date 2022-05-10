/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:03:30 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/10 17:12:54 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_5(t_list **begin_a, t_list **begin_b)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;
	t_list	*fo;
	t_list	*fi;

	f = (*begin_a);
	s = (*begin_a)->next;
	t = (*begin_a)->next->next;
	fo = (*begin_a)->next->next->next;
	fi = (*begin_a)->next->next->next->next;
	if ((f->v < s->v) && (f->v < t->v) && (f->v < fo->v) && (f->v < fi->v))
		ft_push(begin_a, begin_b, 2);
	else if ((f->v > s->v) && (s->v < t->v) && (s->v < fo->v) && (s->v < fi->v))
		ft_min_is_second(begin_a, begin_b);
	else if ((f->v > t->v) && (s->v > t->v) && (t->v < fo->v) && (t->v < fi->v))
		ft_min_is_third(begin_a, begin_b);
	else if ((f->v > fo->v) && (s->v > fo->v) && (t->v > fo->v)
		&& (fo->v < fi->v))
		ft_min_is_fourth(begin_a, begin_b);
	else if ((f->v > fi->v) && (s->v > fi->v) && (t->v > fi->v)
		&& (fo->v > fi->v))
		ft_min_is_fifth(begin_a, begin_b);
	ft_sort_5_nd(begin_a, begin_b);
}

void	ft_min_is_second(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}

void	ft_min_is_third(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a, 1);
	ft_rotate(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}

void	ft_min_is_fourth(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a, 1);
	ft_reverse_rotate(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}

void	ft_min_is_fifth(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}
