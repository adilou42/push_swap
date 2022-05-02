/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:07:56 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:40:34 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_is_sorted(t_list **begin)
{
	t_list	*tmp;

	tmp = *begin;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value && tmp->next)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
