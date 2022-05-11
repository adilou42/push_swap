/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:18:26 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/11 18:42:33 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	free_args(char **args)
{
	char	**tmp;

	tmp = args;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(args);
}

int	ft_parsing_split(int ac, char **av, int i)
{
	char	**args;

	i = 1;
	args = ft_split(av[i], ' ');
	i = 0;
	if (args[i] == NULL)
	{
		write(2, "Error\n", 6);
		free_args(args);
		exit(1);
	}
	if (ft_parsing(ac, args, i) == 0)
	{
		free_args(args);
		return (0);
	}
	free_args(args);
	return (1);
}

int	ft_parsing(int ac, char **av, int i)
{
	(void)ac;
	while (av[i])
	{
		if (av[i] == NULL)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_atoi_max(av[i]) < INT_MIN || ft_atoi_max(av[i]) > INT_MAX)
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

void	arg_error(int ac, char **av, int i)
{
	if (ac > 2)
	{
		if (ft_parsing(ac, av, i) == 0)
			exit(1);
	}
	else if (ac < 2)
	{
		exit(0);
	}
	else if (ac == 2)
	{
		if (ft_parsing_split(ac, av, i) == 0)
			exit(1);
	}
}
