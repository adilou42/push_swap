/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:46:32 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:21:35 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_btoa(t_list **begin_a, t_list **begin_b)
{
	t_list		*tmp_b;
	int			min;
	int			index_a;
	int			index_b;

	index_b = 0;
	index_a = 0;
	tmp_b = *begin_b;
	min = ft_get_min(begin_a);
	while (tmp_b)
	{
		ft_getnxtmov(begin_a, begin_b, index_a, index_b);
		tmp_b = *begin_b;
	}
	ft_last_sort(begin_a, min);
}

void	ft_getnxtmov(t_list **begin_a, t_list **begin_b, int index_a,
					int index_b)
{
	t_list		*tmp_b;
	t_list		*tmp_a;
	int			*tmp_tab;
	int			*final_tab;

	tmp_b = *begin_b;
	tmp_a = *begin_a;
	final_tab = NULL;
	while (tmp_b)
	{
		index_a = ft_index_to_be_in_a(&tmp_a, &tmp_b, index_b);
		tmp_tab = ft_opchoice(begin_a, begin_b, index_a, index_b);
		if (!final_tab || tmp_tab[3] < final_tab[3])
		{
			free(final_tab);
			final_tab = tmp_tab;
		}
		else
			free(tmp_tab);
		index_b++;
		tmp_b = tmp_b->next;
	}
	ft_execmove(final_tab, begin_a, begin_b);
	ft_push(begin_b, begin_a);
	free(final_tab);
}

int	*ft_opchoice(t_list **begin_a, t_list **begin_b, int index_a, int index_b)
{
	int		*tmp_tab;
	int		nb_coups;

	tmp_tab = malloc(sizeof(int) * 4);
	tmp_tab[0] = index_a;
	tmp_tab[1] = index_b;
	tmp_tab[2] = 1;
	tmp_tab[3] = ft_methode1(index_a, index_b);
	nb_coups = ft_methode2(index_a, index_b, begin_a, begin_b);
	if (nb_coups < tmp_tab[3])
		ft_opchoice_meth2(tmp_tab, nb_coups);
	nb_coups = ft_methode3(index_a, index_b, begin_a, begin_b);
	if (nb_coups < tmp_tab[3])
		ft_opchoice_meth3(tmp_tab, nb_coups);
	nb_coups = ft_methode4(index_a, index_b, begin_a, begin_b);
	if (nb_coups < tmp_tab[3])
		ft_opchoice_meth4(tmp_tab, nb_coups);
	return (tmp_tab);
}
