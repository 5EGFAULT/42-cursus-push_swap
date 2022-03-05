/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:01:49 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/15 18:01:51 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*news;

	i = -1;
	if (!s)
		return (0);
	news = malloc(ft_strlen(s) + 1);
	if (!news)
		return (0);
	while (s[++i])
	{
		news[i] = f(i, s[i]);
	}
	news[i] = '\0';
	return (news);
}
