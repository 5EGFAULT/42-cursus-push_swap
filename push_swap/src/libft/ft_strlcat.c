/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:18:58 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/11 15:50:29 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_dst;
	size_t	s_src;

	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	i = 0;
	if (s_dst >= dstsize)
		return (s_src + dstsize);
	while (i < s_src && i + s_dst < dstsize - 1)
	{
		*(dst + i + s_dst) = src[i];
		i++;
	}
	dst[i + s_dst] = '\0';
	return (s_src + s_dst);
}
