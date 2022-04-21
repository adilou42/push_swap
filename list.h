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

void	ft_rotate(t_list **begin);

#endif