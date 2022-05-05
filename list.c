/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:23 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/05 16:03:52 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_display(t_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->character);
		begin = begin->next;
	}
}

t_list	*add_link(t_list *begin, char *c, int value)
{
	t_list	*elem;
	t_list	*tmp;

	elem = malloc(sizeof(t_list));
	tmp = begin;
	if (elem)
	{
		elem->value = value;
		elem->character = c;
		elem->next = NULL;
		elem->prev = NULL;
		if (!begin)
			return (elem);
		while (tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
		elem->prev = tmp;
	}
	return (begin);
}

int	check_doublons(t_list **begin)
{
	t_list	*save1;
	t_list	*save2;

	save1 = *begin;
	while (save1)
	{
		save2 = save1->next;
		while (save2)
		{
			if (save1->value == save2->value)
				return (0);
			save2 = save2->next;
		}
		save1 = save1->next;
	}
	return (1);
}

t_list	*ft_av_to_a_list(t_list **begin, int ac, char **av)
{
	int		i;
	char	**args;
	t_list	*tmp;

	tmp = *begin;
	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		while (args[i])
		{
			tmp = add_link(tmp, args[i], ft_atoi(args[i]));
			i++;
		}
	}
	else
	{
		while (++i < ac)
		{
			tmp = add_link(tmp, av[i], ft_atoi(av[i]));
		}
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	t_list	*begin_a;
	t_list	*begin_b;
	int		size;

	size = 0;
	begin_a = NULL;
	begin_b = NULL;
	arg_error(ac, av);
	begin_a = ft_av_to_a_list(&begin_a, ac, av);
	if (check_doublons(&begin_a) == 0)
	{
		write(2, "Error\n", 6);
		return (ft_lstclear(&begin_a), 0);
	}
	size = ft_lstsize(&begin_a);
	if (ft_is_sorted(&begin_a))
		return (ft_lstclear(&begin_a), 0);
	else if (size <= 5)
		ft_small_sort(&begin_a, &begin_b);
	else
		ft_big_sort(&begin_a, &begin_b);
	ft_display(begin_a);
	return (0);
}
