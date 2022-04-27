/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:18:26 by ayakdi            #+#    #+#             */
/*   Updated: 2022/04/26 17:04:51 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void free_args(char **args)
{
    char **tmp;

    tmp = args;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(args);
}

int ft_parsing_split(int ac, char **av)
{
    char **args;
    int i;

    i = 0;
    args = ft_split(av[1], ' ');
    if (!args[i])
    {
        write(2, "Error\n", 6);
        free_args(args);
        return (0);
    }
    if (!ft_parsing(ac, args))
    {
        free_args(args);
        return (0);
    }
    free_args(args);
    return (1);
}

int ft_parsing(int ac, char **av)
{
    (void)ac;
    int i;

    i = 1;
    while (av[i])
    {
        if (!av[i])
        {
            write(2, "Error\n", 6);
            return (0);
        }
        else if (ft_atoi_max(av[i]) < INT_MIN || ft_atoi_max(av[i]) > INT_MAX)
        {
            write(2, "Error\n", 6);
            return (0);
        }
        else if (!ft_isnum(av[i]) || ft_strlen(av[i]) == 0)
        {
            write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
    return (1);
}

int arg_error(int ac, char **av)
{
    if (ac > 2)
    {
        if (!ft_parsing(ac, av))
            return (0);
    }
    else if (ac < 2)
    {
        exit(0);
    }
    else if (ac == 2)
    {
        if (!ft_parsing_split(ac, av))
            return (0);
    }
}