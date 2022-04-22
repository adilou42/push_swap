/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:45:23 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/21 18:35:58 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_display(t_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->character);
		begin = begin->next;
	}
}

t_list *add_link(t_list *begin, char *c)
{
	t_list *elem;
	t_list *tmp;

	elem = malloc(sizeof(t_list));
	tmp = begin;
	if (elem)
	{
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

int main(int ac, char **av)
{
	t_list *begin_a;
	t_list *begin_b;

	begin_a = NULL;
	begin_b = NULL;

	int i = 1;

	while (i < ac)
	{
		begin_a = add_link(begin_a, av[i]);
		i++;
	}

	ft_display(begin_a);
	printf("AAAAAAA\n");
	ft_display(begin_b);
	printf("AAAAAAA\n");

	ft_push(&begin_a, &begin_b);
	ft_push(&begin_a, &begin_b);
	ft_push(&begin_a, &begin_b);
	ft_display(begin_a);
	printf("AAAAAAA\n");
	ft_display(begin_b);
	printf("AAAAAAA\n");

	ft_ss(&begin_a, &begin_b);

	ft_display(begin_a);
	printf("AAAAAAA\n");
	ft_display(begin_b);

	return (0);
}