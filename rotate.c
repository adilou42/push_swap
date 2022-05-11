/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:14 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/11 18:46:17 by ayakdi           ###   ########.fr       */
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
	t_list	*tmp;
	t_list	*last;
	t_list	*a;

	a = *begin;
	while (a->next)
	{
		tmp = a->next;
		last = a;
		a = a->next;
	}
	last->next = NULL;
	tmp->next = *begin;
	*begin = tmp;
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
