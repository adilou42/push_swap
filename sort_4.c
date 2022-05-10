/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:16:52 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/10 17:13:24 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_4(t_list **begin_a, t_list **begin_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*first_b;

	ft_push(begin_a, begin_b, 2);
	ft_sort_3(begin_a);
	first = *begin_a;
	second = (*begin_a)->next;
	third = (*begin_a)->next->next;
	first_b = (*begin_b);
	if ((first_b->v < first->v) && (first_b->v < second->v)
		&& (first_b->v < third->v))
		ft_push(begin_b, begin_a, 1);
	else if ((first_b->v > first->v) && (first_b->v < second->v)
		&& (first_b->v < third->v))
		fb_is_second(begin_a, begin_b);
	else if ((first_b->v > first->v) && (first_b->v > second->v)
		&& first_b->v < third->v)
		fb_is_third(begin_a, begin_b);
	else if ((first_b->v > first->v) && (first_b->v > second->v)
		&& (first_b->v > third->v))
		fb_is_fourth(begin_a, begin_b);
}

void	fb_is_second(t_list **begin_a, t_list **begin_b)
{
	ft_push(begin_b, begin_a, 1);
	ft_swap(begin_a, 1);
}

void	fb_is_third(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a, 1);
	ft_push(begin_b, begin_a, 1);
	ft_reverse_rotate(begin_a, 1);
	ft_reverse_rotate(begin_a, 1);
}

void	fb_is_fourth(t_list **begin_a, t_list **begin_b)
{
	ft_push(begin_b, begin_a, 1);
	ft_rotate(begin_a, 1);
}
