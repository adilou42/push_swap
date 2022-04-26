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
	int count;
	int x;
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
char **ft_split(char const *s, char c);
void ft_lstclear(t_list **begin);
int ft_lstsize(t_list **begin);

#endif