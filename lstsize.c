/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:08:12 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 18:42:38 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int ft_lstsize(t_list **begin)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *begin;

	while (tmp)
	{
		tmp = tmp->next;
		// printf("count=%d\n", count);
		count++;
	}
	return (count);
}