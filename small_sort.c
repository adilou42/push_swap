/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:07:45 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 18:51:02 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void ft_sort_3(t_list **begin)
{
	t_list *first;
	t_list *second;
	t_list *third;

	first = *begin;
	second = (*begin)->next;
	third = (*begin)->next->next;
	if ((first->value > second->value) && (second->value > third->value) && (third->value < first->value))
	{
		ft_rotate(begin);
		ft_swap(begin);
	}
	else if ((first->value > second->value) && (second->value < third->value) && (third->value < first->value))
		ft_rotate(begin);
	else if ((first->value > second->value) && (second->value < third->value) && (third->value > first->value))
		ft_swap(begin);
	else if ((first->value < second->value) && (second->value > third->value) && (third->value < first->value))
		ft_reverse_rotate(begin);
	else if ((first->value < second->value) && (second->value > third->value) && (third->value > first->value))
	{
		ft_reverse_rotate(begin);
		ft_swap(begin);
	}
}

void ft_sort_2(t_list **begin)
{
	t_list *tmp_first;
	t_list *tmp_second;

	tmp_first = *begin;
	tmp_second = (*begin)->next;
	// if (tmp_first->value > tmp_second->value)
	ft_swap(begin);
}

void ft_small_sort(t_list **begin_a, t_list **begin_b)
{
	int size;

	size = ft_lstsize(begin_a);
	printf("size = %d\n", size);

	if (!(ft_is_sorted(begin_a) && size == 2))
	{
		ft_display(*begin_a);
		write(1, "AA\n", 3);
		ft_swap(begin_a);
		ft_display(*begin_a);
	}
	else
	{
	}
}