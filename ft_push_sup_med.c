/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sup_med.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:06:31 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/28 19:07:56 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_push_sup_med(t_list **begin_a, t_list **begin_b, int med)
{
	t_list	*tmp_A;
	t_list	*tmp_B;
	int			min;
	int			max;

	tmp_A = *begin_a;
	tmp_B = *begin_b;
	min = ft_get_min(&tmp_A);
	max = ft_get_max(&tmp_A);
	if ((tmp_A->value != med) && (tmp_A->value != min) && (tmp_A->value != max))
		ft_push(&tmp_A, &tmp_B);
	else
		ft_rotate(&tmp_A);
	*begin_a = tmp_A;
	*begin_b = tmp_B;
}