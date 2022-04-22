#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef list_h
#define list_h

typedef struct s_list t_list;

struct s_list
{
	char *character;
	t_list *next;
	t_list *prev;
};

void ft_rotate(t_list **begin);
void ft_ss(t_list **begin_a, t_list **begin_b);
void ft_swap(t_list **begin);
void ft_push(t_list **begin_a, t_list **begin_b);
void ft_rr(t_list **begin_a, t_list **begin_b);
void ft_reverse_rotate(t_list **begin);
void ft_rrr(t_list **begin_a, t_list **begin_b);

#endif