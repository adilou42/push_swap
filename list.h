#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#ifndef list_h
#define list_h

typedef struct s_list t_list;

struct s_list
{
	char *character;
	int count;
	int value;
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
int ft_check_doublons(t_list **begin);
int ft_is_sorted(t_list **begin);
void ft_small_sort(t_list **begin_a, t_list **begin_b);
int ft_atoi(char *str);
long long ft_atoi_max(char *str);
int ft_isnum(char *num);
int ft_strlen(char *str);
int ft_isdigit(int c);
int arg_error(int ac, char **av);
int ft_parsing(int ac, char **av);
int ft_parsing_split(int ac, char **av);
void free_args(char **args);
void ft_sort_4(t_list **begin_a, t_list **begin_b);
void fb_is_second(t_list **begin_a, t_list **begin_b);
void fb_is_third(t_list **begin_a, t_list **begin_b);
void fb_is_fourth(t_list **begin_a, t_list **begin_b);
void ft_sort_3(t_list **begin);
void ft_display(t_list *begin);
int	ft_get_min(t_list **begin);
int	ft_get_max(t_list **begin);
void	ft_sort_5(t_list **begin_a, t_list **begin_b);
void	ft_min_is_second(t_list **begin_a, t_list **begin_b);
void	ft_min_is_third(t_list **begin_a, t_list **begin_b);
void	ft_min_is_fourth(t_list **begin_a, t_list **begin_b);
void	ft_min_is_fifth(t_list **begin_a, t_list **begin_b);
void	ft_sort_5_nd(t_list **begin_a, t_list **begin_b);
void	ft_min_is_second_2(t_list **begin_a, t_list **begin_b);
void	ft_min_is_third_2(t_list **begin_a, t_list **begin_b);
void	ft_min_is_fourth_2(t_list **begin_a, t_list **begin_b);
void	ft_big_sort(t_list **begin_a, t_list **begin_b);
int	ft_recup_mediane(t_list **begin_a);
void	ft_index(t_list **begin);
void	ft_push_sup_med(t_list **begin_a, t_list **begin_b, int med);


#endif