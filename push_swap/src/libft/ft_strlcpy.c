/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:17:19 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/07 16:17:21 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(src);
	k = -1;
	if (dstsize)
	{
		while (++k < dstsize - 1 && k < i)
			*(dst + k) = src[k];
		*(dst + k) = '\0';
	}		
	return (i);
}
