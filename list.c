/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:23 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/17 20:07:48 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_display(t_list *begin)
{
	while (begin != NULL)
	{
		printf("%d\n", begin->v);
		begin = begin->next;
	}
}

t_list	*ft_add_back(t_list *begin_a, int v)
{
	t_list	*a;
	t_list	*tmp;

	a = malloc(sizeof(t_list));
	tmp = NULL;
	tmp = begin_a;
	if (a != NULL)
	{
		a->v = v;
		a->count = 0;
		a->next = NULL;
	}
	if (!tmp)
		begin_a = a;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
	return (begin_a);
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
			if (save1->v == save2->v)
				return (0);
			save2 = save2->next;
		}
		save1 = save1->next;
	}
	return (1);
}

t_list	*ft_av_to_a_list(int ac, char **av)
{
	int		i;
	char	**args;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		while (args[i])
		{
			tmp = ft_add_back(tmp, ft_atoi(args[i]));
			i++;
		}
		free_args(args);
	}
	else
	{
		while (++i < ac)
		{
			tmp = ft_add_back(tmp, ft_atoi(av[i]));
		}
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	t_list	*begin_a;
	t_list	*begin_b;
	int		size;
	int		i;

	size = 0;
	i = 1;
	begin_a = NULL;
	begin_b = NULL;
	arg_error(ac, av, i);
	begin_a = ft_av_to_a_list(ac, av);
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
	ft_lstclear(&begin_a);
	return (0);
}
