/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:30:20 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/13 23:30:21 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = -1;
	if (s && start < ft_strlen(s))
	{
		res = (char *)malloc(len + 1);
		if (!(res))
			return (0);
		while (s[++i + start] && (size_t) i < len)
			res[i] = s[i + start];
		res[i] = '\0';
		return (res);
	}
	if (s && start >= ft_strlen(s))
		return (ft_strdup(""));
	return (0);
}
