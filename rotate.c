/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:14 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:12:49 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_rotate(t_list **begin)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*begin);
	tmp2 = (*begin);
	(*begin) = (*begin)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	(*begin)->prev = NULL;
	tmp2->next = tmp;
	tmp->prev = tmp2;
}

void	ft_rr(t_list **begin_a, t_list **begin_b)
{
	ft_rotate(begin_a);
	ft_rotate(begin_b);
}

void	ft_reverse_rotate(t_list **begin)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	tmp_first = *begin;
	tmp_last = *begin;
	while (tmp_last && tmp_last->next)
		tmp_last = tmp_last->next;
	*begin = tmp_last;
	tmp_last = tmp_last->prev;
	(*begin)->prev = NULL;
	(*begin)->next = tmp_first;
	tmp_last->next = NULL;
	tmp_first->prev = *begin;
}

void	ft_rrr(t_list **begin_a, t_list **begin_b)
{
	ft_reverse_rotate(begin_a);
	ft_reverse_rotate(begin_b);
}
