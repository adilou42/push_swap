/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:14 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/21 17:21:16 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"


void	ft_rotate(t_list **begin)
{
	t_list *tmp;
	t_list	*tmp2;

	tmp = (*begin);
	tmp2 = (*begin);
	(*begin) = (*begin)->next;

	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}

	tmp->prev = NULL;
	tmp->next = NULL;
	(*begin)->prev = NULL;

	tmp2->next = tmp;
	tmp->prev = tmp2;

}

void	ft_rr(t_list	**begin_a, t_list	**begin_b)
 {
	 ft_rotate(begin_a);
	 ft_rotate(begin_b);
 }