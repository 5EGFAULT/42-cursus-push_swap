/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:19:20 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/14 22:19:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**empty_2d_array(char const *s, char c)
{
	int		i;
	int		len2;
	char	**splited;

	i = -1;
	len2 = 0;
	while (s[++i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			len2++;
		else
		{
			if (i == 0 && s[i] != c)
				len2++;
		}
	}
	splited = (char **)malloc((len2 + 1) * sizeof(char *));
	return (splited);
}

static int	fill_2d_array(char const *s, char c, char **splited)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	k = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			j = -1;
			while (s[i + ++j] && s[i + j] != c)
				;
			splited[++k] = (char *)malloc(j + 1);
			if (!splited[k])
				return (0);
			j = -1;
			while (s[i + ++j] && s[i + j] != c)
				splited[k][j] = s[i + j];
			splited[k][j] = '\0';
			i = i + j -1;
		}
	}
	splited[++k] = (char *)0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (0);
	splited = empty_2d_array(s, c);
	if (!splited)
		return ((char **)0);
	if (fill_2d_array(s, c, splited))
		return (splited);
	return ((char **)0);
}
