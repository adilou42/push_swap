/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:07:45 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:42:25 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_3(t_list **begin)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *begin;
	second = (*begin)->next;
	third = (*begin)->next->next;
	if ((first->value > second->value) && (second->value > third->value)
		&& (third->value < first->value))
	{
		ft_rotate(begin);
		ft_swap(begin);
	}
	else if ((first->value > second->value) && (second->value < third->value)
		&& (third->value < first->value))
		ft_rotate(begin);
	else if ((first->value > second->value) && (second->value < third->value)
		&& (third->value > first->value))
		ft_swap(begin);
	else if ((first->value < second->value) && (second->value > third->value)
		&& (third->value < first->value))
		ft_reverse_rotate(begin);
	else if ((first->value < second->value) && (second->value > third->value)
		&& (third->value > first->value))
	{
		ft_reverse_rotate(begin);
		ft_swap(begin);
	}
}

void	ft_small_sort(t_list **begin_a, t_list **begin_b)
{
	int	size;

	size = ft_lstsize(begin_a);
	if ((ft_is_sorted(begin_a) == 0) && size == 2)
	{
		ft_swap(begin_a);
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
