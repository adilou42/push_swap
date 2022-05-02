/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executes_methods_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:31:04 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:36:48 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define A 0
#define B 1
#define R 2

void	ft_execution1(t_list **begin_a, t_list **begin_b, int ra, int rb)
{
	while (ra)
	{
		ft_rotate(begin_a);
		ra--;
	}
	while (rb)
	{
		ft_rotate(begin_b);
		rb--;
	}
}

void	ft_execution2(t_list **begin_a, t_list **begin_b, int *rrr)
{
	while (rrr[A])
	{
		ft_reverse_rotate(begin_a);
		rrr[A]--;
	}
	while (rrr[B])
	{
		ft_reverse_rotate(begin_b);
		rrr[B]--;
	}
}

void	ft_execution3(t_list **begin_a, t_list **begin_b, int *rrr)
{
	while (rrr[R])
	{
		ft_rrr(begin_a, begin_b);
		rrr[R]--;
	}
}
