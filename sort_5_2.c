/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:19:26 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/17 16:20:42 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_5_nd(t_list **begin_a, t_list **begin_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;

	first = (*begin_a);
	second = (*begin_a)->next;
	third = (*begin_a)->next->next;
	fourth = (*begin_a)->next->next->next;
	if ((first->v < second->v) && (first->v < third->v)
		&& (first->v < fourth->v))
		ft_push(begin_a, begin_b, 2);
	else if ((first->v > second->v) && (second->v < third->v)
		&& (second->v < fourth->v))
		ft_min_is_second_2(begin_a, begin_b);
	else if ((first->v > third->v) && (second->v > third->v)
		&& (third->v < fourth->v))
		ft_min_is_third_2(begin_a, begin_b);
	else if ((first->v > fourth->v) && (second->v > fourth->v)
		&& (third->v > fourth->v))
		ft_min_is_fourth_2(begin_a, begin_b);
	ft_sort_3(begin_a);
	ft_push(begin_b, begin_a, 1);
	ft_push(begin_b, begin_a, 1);
}

void	ft_min_is_second_2(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}

void	ft_min_is_third_2(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a, 1);
	ft_rotate(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}

void	ft_min_is_fourth_2(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a, 1);
	ft_push(begin_a, begin_b, 2);
}
