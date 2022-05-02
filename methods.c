/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:48:44 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:44:47 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_methode1(int index_a, int index_b)
{
	if (index_a >= index_b)
		return (index_a);
	return (index_b);
}

int	ft_methode2(int index_a, int index_b, t_list **begin_a, t_list **begin_b)
{
	t_list	*a;
	t_list	*b;
	int		rindex_a;
	int		rindex_b;

	a = *begin_a;
	b = *begin_b;
	rindex_a = 0;
	rindex_b = 0;
	if (index_a)
		rindex_a = ft_lstsize(&a) - index_a;
	if (index_b)
		rindex_b = ft_lstsize(&b) - index_b;
	if (rindex_a >= rindex_b)
		return (rindex_a);
	return (rindex_b);
}

int	ft_methode3(int index_a, int index_b, t_list **begin_a, t_list **begin_b)
{
	t_list	*b;
	int		rindex_b;

	(void)begin_a;
	rindex_b = 0;
	b = *begin_b;
	if (index_b)
		rindex_b = ft_lstsize(&b) - index_b;
	return (index_a + rindex_b);
}

int	ft_methode4(int index_a, int index_b, t_list **begin_a, t_list **begin_b)
{
	t_list	*a;
	int		rindex_a;

	(void)begin_b;
	a = *begin_a;
	rindex_a = 0;
	if (index_a)
		rindex_a = ft_lstsize(&a) - index_a;
	return (index_b + rindex_a);
}
