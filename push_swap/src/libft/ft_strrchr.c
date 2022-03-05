/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:09:19 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/06 15:09:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i] != '\0')
	{
		if ((char) c == s[i])
			tmp = (char *)(s + i);
		i++;
	}
	if (tmp != NULL)
		return (tmp);
	if ((char) c == s[i])
		return ((char *)(s + i));
	return (NULL);
}
