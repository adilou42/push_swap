/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:14 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/09 19:51:42 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_rotate(t_list **begin, int nbr)
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
	if (nbr == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b)
{
	ft_rotate(begin_a, nbr_a);
	ft_rotate(begin_b, nbr_b);
}

void	ft_reverse_rotate(t_list **begin, int nbr)
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
	if (nbr == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b)
{
	ft_reverse_rotate(begin_a, nbr_a);
	ft_reverse_rotate(begin_b, nbr_b);
}
