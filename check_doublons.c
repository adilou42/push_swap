/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doublons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:09:28 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 14:53:50 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int ft_check_doublons(t_list **begin)
{
    t_list *tmp1;
    t_list *tmp2;

    tmp1 = *begin;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        while (tmp2)
        {
            if (tmp1->value == tmp2->value)
                return (0);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    return (1);
}