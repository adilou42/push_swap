/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:16:52 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 17:44:40 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_sort_4(t_list **begin_a, t_list **begin_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*first_b;

	ft_push(begin_a, begin_b);
	ft_sort_3(begin_a);
	first = *begin_a;
	second = (*begin_a)->next;
	third = (*begin_a)->next->next;
	first_b = (*begin_b);
	if ((first_b->value < first->value) && (first_b->value < second->value) && (first_b->value < third->value))
		ft_push(begin_b, begin_a);
	else if ((first_b->value > first->value) && (first_b->value < second->value) && (first_b->value < third->value))
		ft_action_for_fb_is_2(begin_a, begin_b);
	else if ((first_b->value > first->value) && (first_b->value > second->value) && first_b->value < third->value)
		ft_action_for_fb_is_3(begin_a, begin_b);
	else if ((first_b->value > first->value) && (first_b->value > second->value) && (first_b->value > third->value))
		ft_action_for_fb_is_4(begin_a, begin_b);
}

void	ft_action_for_fb_is_2(t_list **begin_a, t_list **begin_b)
{
	ft_push(begin_b, begin_a);
	ft_swap(begin_a);
}

void	ft_action_for_fb_is_3(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a);
	ft_push(begin_b, begin_a);
	ft_reverse_rotate(begin_a);
	ft_reverse_rotate(begin_a);
}

void	ft_action_for_fb_is_4(t_list **begin_a, t_list **begin_b)
{
	ft_push(begin_b, begin_a);
	ft_rotate(begin_a);
}