/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:19:27 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/05 19:50:54 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

struct s_list
{
	char	*character;
	int		count;
	int		value;
	t_list	*next;
	t_list	*prev;
};

void		ft_rotate(t_list **begin, int nbr);
void		ft_ss(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b);
void		ft_swap(t_list **begin, int nbr);
void		ft_push(t_list **begin_a, t_list **begin_b, int nbr);
void		ft_rr(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b);
void		ft_reverse_rotate(t_list **begin, int nbr);
void		ft_rrr(t_list **begin_a, t_list **begin_b, int nbr_a, int nbr_b);
char		**ft_split(char const *s, char c);
void		ft_lstclear(t_list **begin);
int			ft_lstsize(t_list **begin);
int			ft_check_doublons(t_list **begin);
int			ft_is_sorted(t_list **begin);
void		ft_small_sort(t_list **begin_a, t_list **begin_b);
int			ft_atoi(char *str);
long long	ft_atoi_max(char *str);
int			ft_isnum(char *num);
int			ft_strlen(char *str);
int			ft_isdigit(int c);
int			arg_error(int ac, char **av);
int			ft_parsing(int ac, char **av);
int			ft_parsing_split(int ac, char **av);
void		free_args(char **args);
void		ft_sort_4(t_list **begin_a, t_list **begin_b);
void		fb_is_second(t_list **begin_a, t_list **begin_b);
void		fb_is_third(t_list **begin_a, t_list **begin_b);
void		fb_is_fourth(t_list **begin_a, t_list **begin_b);
void		ft_sort_3(t_list **begin);
void		ft_display(t_list *begin);
int			ft_get_min(t_list **begin);
int			ft_get_max(t_list **begin);
void		ft_sort_5(t_list **begin_a, t_list **begin_b);
void		ft_min_is_second(t_list **begin_a, t_list **begin_b);
void		ft_min_is_third(t_list **begin_a, t_list **begin_b);
void		ft_min_is_fourth(t_list **begin_a, t_list **begin_b);
void		ft_min_is_fifth(t_list **begin_a, t_list **begin_b);
void		ft_sort_5_nd(t_list **begin_a, t_list **begin_b);
void		ft_min_is_second_2(t_list **begin_a, t_list **begin_b);
void		ft_min_is_third_2(t_list **begin_a, t_list **begin_b);
void		ft_min_is_fourth_2(t_list **begin_a, t_list **begin_b);
void		ft_big_sort(t_list **begin_a, t_list **begin_b);
int			ft_recup_mediane(t_list **begin_a);
void		ft_index(t_list **begin);
void		ft_push_sup_med(t_list **begin_a, t_list **begin_b, int med);
void		ft_btoa(t_list **begin_a, t_list **begin_b);
void		ft_getnxtmov(t_list **begin_a, t_list **begin_b, int index_a,
				int index_b);
int			*ft_opchoice(t_list **begin_a, t_list **begin_b, int index_a,
				int index_b);
void		ft_opchoice_meth2(int *tmp_tab, int nb_coups);
void		ft_opchoice_meth3(int *tmp_tab, int nb_coups);
void		ft_opchoice_meth4(int *tmp_tab, int nb_coups);
void		ft_execmove(int *tab, t_list **begin_a, t_list **begin_b);
void		ft_exec1(int *tab, t_list **begin_a, t_list **begin_b);
void		ft_exec2(int *tab, t_list **begin_a, t_list **begin_b, int rinda);
void		ft_exec3(int *tab, t_list **begin_a, t_list **begin_b);
void		ft_exec4(int *tab, t_list **begin_a, t_list **begin_b);
void		ft_execution1(t_list **begin_a, t_list **begin_b, int ra, int rb);
void		ft_execution2(t_list **begin_a, t_list **begin_b, int *rrr);
void		ft_execution3(t_list **begin_a, t_list **begin_b, int *rrr);
int			ft_loop_ls(t_list **begin_a, int min, int i);
void		ft_last_sort(t_list **begin_a, int min);
int			ft_methode1(int index_a, int index_b);
int			ft_methode2(int index_a, int index_b, t_list **begin_a,
				t_list **begin_b);
int			ft_methode3(int index_a, int index_b, t_list **begin_a,
				t_list **begin_b);
int			ft_methode4(int index_a, int index_b, t_list **begin_a,
				t_list **begin_b);
int			ft_index_to_be_in_a(t_list **begin_a, t_list **begin_b,
				int index_a);
#endif