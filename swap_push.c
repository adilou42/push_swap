/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:08:19 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/05 19:51:43 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_swap(t_list **begin, int nbr)
{
	t_list	*tmp;

	tmp = *begin;
	if (*begin && (*begin)->next)
	{
		*begin = (*begin)->next;
		(*begin)->prev = NULL;
	}
	else
		(*begin) = NULL;
	tmp->prev = *begin;
	if ((*begin)->next)
		tmp->next = (*begin)->next;
	else
		tmp->next = NULL;
	(*begin)->next = tmp;
	if (nbr == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b)
{
	ft_swap(begin_a, nbr_a);
	ft_swap(begin_b, nbr_b);
}

void	ft_push(t_list **begin_a, t_list **begin_b, int nbr)
{
	t_list	*tmp_a;

	tmp_a = (*begin_a);
	if ((*begin_a) && (*begin_a)->next)
	{
		(*begin_a) = (*begin_a)->next;
		(*begin_a)->prev = NULL;
	}
	else
		(*begin_a) = NULL;
	tmp_a->next = (*begin_b);
	if (*begin_b)
		(*begin_b)->prev = tmp_a;
	*begin_b = tmp_a;
	if (nbr == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
