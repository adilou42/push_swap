/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:12:10 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 17:02:18 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	while (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_index_to_be_in_a(t_list **begin_a, t_list **begin_b, int index_a)
{
	t_list	*a;
	t_list	*b;

	a = *begin_a;
	b = *begin_b;
	index_a = 0;
	a = *begin_a;
	while (a && a->value > b->value)
	{
		index_a++;
		a = a->next;
	}
	if (a && a->value < b->value)
	{
		while (a && a->value < b->value)
		{
			index_a++;
			a = a->next;
		}
	}
	else
		index_a = 0;
	return (index_a);
}
