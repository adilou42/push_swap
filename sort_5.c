/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:03:30 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/28 18:33:10 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_5(t_list **begin_a, t_list **begin_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*fifth;

	first = (*begin_a);
	second = (*begin_a)->next;
	third = (*begin_a)->next->next;
	fourth = (*begin_a)->next->next->next;
	fifth = (*begin_a)->next->next->next->next;
	if ((first->value < second->value) && (first->value < third->value) && (first->value < fourth->value) && (first->value < fifth->value))
		ft_push(begin_a, begin_b);
	else if ((first->value > second->value) && (second->value < third->value) && (second->value < fourth->value) && (second->value < fifth->value))
		ft_min_is_second(begin_a, begin_b);
	else if ((first->value > third->value) && (second->value > third->value) && (third->value < fourth->value) && (third->value < fifth->value))
		ft_min_is_third(begin_a, begin_b);
	else if ((first->value > fourth->value) && (second->value > fourth->value)
		&& (third->value > fourth->value) && (fourth->value < fifth->value))
		ft_min_is_fourth(begin_a, begin_b);
	else if ((first->value > fifth->value) && (second->value > fifth->value)
		&& (third->value > fifth->value) && (fourth->value > fifth->value))
		ft_min_is_fifth(begin_a, begin_b);
	ft_sort_5_nd(begin_a, begin_b);
}

void	ft_min_is_second(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a);
	ft_push(begin_a, begin_b);
}

void	ft_min_is_third(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a);
	ft_rotate(begin_a);
	ft_push(begin_a, begin_b);
}

void	ft_min_is_fourth(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a);
	ft_reverse_rotate(begin_a);
	ft_push(begin_a, begin_b);
}

void	ft_min_is_fifth(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a);
	ft_push(begin_a, begin_b);
}