/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:59:44 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/28 16:00:20 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_get_min(t_list **begin)
{
	t_list	*tmp;
	int			x;

	tmp = *begin;
	x = INT_MAX;
	while (tmp)
	{
		if (x > tmp->value)
			x = tmp->value;
		tmp = tmp->next;
	}
	return (x);
}

int	ft_get_max(t_list **begin)
{
	t_list	*tmp;
	int			x;

	tmp = *begin;
	x = INT_MIN;
	while (tmp)
	{
		if (x < tmp->value)
			x = tmp->value;
		tmp = tmp->next;
	}
	return (x);
}