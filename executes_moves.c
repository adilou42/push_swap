/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executes_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:25:03 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/05 19:49:46 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define A 0
#define B 1
#define R 2

void	ft_execmove(int *tab, t_list **begin_a, t_list **begin_b)
{
	int	rinda;

	rinda = 0;
	if (tab[2] == 1)
		ft_exec1(tab, begin_a, begin_b);
	else if (tab[2] == 2)
		ft_exec2(tab, begin_a, begin_b, rinda);
	else if (tab[2] == 3)
		ft_exec3(tab, begin_a, begin_b);
	else if (tab[2] == 4)
		ft_exec4(tab, begin_a, begin_b);
}

void	ft_exec1(int *tab, t_list **begin_a, t_list **begin_b)
{
	int	rr;
	int	ra;
	int	rb;

	ra = 0;
	rb = 0;
	if (tab[0] <= tab[1])
	{
		rr = tab[0];
		if (tab[0] != tab[1])
			rb = tab[1] - rr;
	}
	else
	{
		rr = tab[1];
		ra = tab[0] - rr;
	}
	while (rr)
	{
		ft_rr(begin_a, begin_b, 1, 2);
		rr--;
	}
	ft_execution1(begin_a, begin_b, ra, rb);
}

void	ft_exec2(int *tab, t_list **begin_a, t_list **begin_b, int rinda)
{
	int	rrr[3];
	int	rindex_b;

	rrr[A] = 0;
	rrr[B] = 0;
	rrr[R] = 0;
	rinda = 0;
	rindex_b = 0;
	if (tab[0])
		rinda = ft_lstsize(begin_a) - tab[0];
	if (tab[1])
		rindex_b = ft_lstsize(begin_b) - tab[1];
	if (rinda <= rindex_b)
	{
		rrr[R] = rinda;
		if (rinda != rindex_b)
			rrr[B] = rindex_b - rrr[R];
	}
	else
	{
		rrr[R] = rindex_b;
		rrr[A] = rinda - rrr[R];
	}
	ft_execution2(begin_a, begin_b, rrr);
	ft_execution3(begin_a, begin_b, rrr);
}

void	ft_exec3(int *tab, t_list **begin_a, t_list **begin_b)
{
	int	rindex_b;

	rindex_b = 0;
	if (tab[1])
		rindex_b = ft_lstsize(begin_b) - tab[1];
	while (tab[0])
	{
		ft_rotate(begin_a, 1);
		tab[0]--;
	}
	while (rindex_b)
	{
		ft_reverse_rotate(begin_b, 2);
		rindex_b--;
	}
}

void	ft_exec4(int *tab, t_list **begin_a, t_list **begin_b)
{
	int	rindex_a;

	rindex_a = 0;
	if (tab[0])
		rindex_a = ft_lstsize(begin_a) - tab[0];
	while (tab[1])
	{
		ft_rotate(begin_b, 2);
		tab[1]--;
	}
	while (rindex_a)
	{
		ft_reverse_rotate(begin_a, 1);
		rindex_a--;
	}
}
