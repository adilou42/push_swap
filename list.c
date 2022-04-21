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


void	ft_display(t_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->character);
		begin = begin->next;
	}
}

void	ft_reverse_rotate(t_list	**begin)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	tmp_first = (*begin);
	tmp_last = (*begin);

	while (tmp_last->next)
		tmp_last = tmp_last->next;
	(*begin) = tmp_last;
	tmp_last = tmp_last->prev;
	(*begin)->prev = NULL;
	(*begin)->next = tmp_first;
	tmp_last->next = NULL;
	tmp_first->prev = (*begin);

}

void	ft_rrr(t_list	**begin_a, t_list	**begin_b)
{
	ft_reverse_rotate(begin_a);
	ft_reverse_rotate(begin_b);
}


t_list	*ft_swap(t_list *begin)
{
	t_list *tmp;

	tmp = begin;

	begin = begin->next;
	tmp->prev = NULL;
	tmp->next = NULL;

	begin->prev = NULL;
	begin->next = tmp;
	tmp->prev = begin;
	tmp->next = NULL;

	return (begin);
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
		
		while(tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
		elem->prev = tmp;
	}
	return (begin);
}

void	ft_push(t_list	**begin_a, t_list	**begin_b)
 {

	 t_list	*tmp_A;

	 tmp_A = (*begin_a);
	 if ((*begin_a) && (*begin_a)->next)
	 {
	 	(*begin_a) = (*begin_a)->next;
	 	(*begin_a)->prev = NULL;
		 tmp_A->prev = NULL;
	 }
	 else
	 {
		 (*begin_a) = NULL;
	 }
	 tmp_A->next = (*begin_b);
	//  tmp_A->prev = NULL;
	 (*begin_b) = tmp_A;
	 if (!(*begin_b)->next)
		 (*begin_b)->next = NULL;

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

	// ft_push(&begin_a, &begin_b);
	// ft_push(&begin_a, &begin_b);
	// ft_push(&begin_a, &begin_b);
	// ft_rrr(&begin_a, &begin_b);
	// ft_display(begin_a);
	// ft_display(begin_b);

	ft_push(&begin_a, &begin_b);
	ft_push(&begin_a, &begin_b);
	ft_push(&begin_a, &begin_b);
	ft_display(begin_b);
	ft_reverse_rotate(&begin_a);
	ft_reverse_rotate(&begin_b);
	printf("AAAAAAAA\n");
	ft_display(begin_a);
	printf("BBBBBB\n");
	ft_display(begin_b);

	// ft_rrr(&begin_a, &begin_b);
	// ft_push(&begin_a, &begin_b);
	// ft_push(&begin_a, &begin_b);
	
	return (0);
}