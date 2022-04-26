/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:08:19 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 14:12:49 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void ft_swap(t_list **begin)
{
	t_list *tmp;

	tmp = *begin;

	if (*begin && (*begin)->next)
	{
		*begin = (*begin)->next;
		(*begin)->prev = NULL;
	}
	else
	{
		(*begin) = NULL;
	}

	tmp->prev = *begin;
	if ((*begin)->next)
		tmp->next = (*begin)->next;
	else
		tmp->next = NULL;
	(*begin)->next = tmp;
}

void ft_ss(t_list **begin_a, t_list **begin_b)
{
	ft_swap(begin_a);
	ft_swap(begin_b);
}

void ft_push(t_list **begin_a, t_list **begin_b)
{

	t_list *tmp_A;

	tmp_A = (*begin_a);
	if ((*begin_a) && (*begin_a)->next)
	{
		(*begin_a) = (*begin_a)->next;
		(*begin_a)->prev = NULL;
	}
	else
	{
		(*begin_a) = NULL;
	}
	tmp_A->next = (*begin_b);
	if (*begin_b)
		(*begin_b)->prev = tmp_A;
	*begin_b = tmp_A;
}