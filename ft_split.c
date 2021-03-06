/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <ayakdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:08:01 by ayakdi            #+#    #+#             */
/*   Updated: 2022/05/02 19:35:39 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	ft_ischarset(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_countwords(char const *str, char sep)
{
	int	wc;
	int	i;

	i = 0;
	wc = 0;
	while (str[i] && ft_ischarset(str[i], sep))
		i++;
	while (str[i])
	{
		wc++;
		while (str[i] && !ft_ischarset(str[i], sep))
			i++;
		while (str[i] && ft_ischarset(str[i], sep))
			i++;
	}
	return (wc);
}

static char	*ft_dup(char const *str, char sep)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	i = 0;
	while (str[len] && !ft_ischarset(str[len], sep))
		len++;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (str[i] && !ft_ischarset(str[i], sep))
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && ft_ischarset(s[i], c))
		i++;
	while (s[i])
	{
		split[j] = ft_dup(&s[i], c);
		while (s[i] && !ft_ischarset(s[i], c))
			i++;
		while (s[i] && ft_ischarset(s[i], c))
			i++;
		j++;
	}
	split[j] = 0;
	return (split);
}
