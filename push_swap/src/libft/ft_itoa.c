/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:37:36 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/15 14:37:38 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	tmp;
	int	len;

	tmp = n / 10;
	len = 1;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;
	long	tmp;
	int		i;

	length = get_length(n);
	str = (char *)malloc(length + 1);
	if (!str)
		return (0);
	i = -1;
	tmp = n;
	if (n < 0)
		str[++i] = '-';
	if (n < 0)
		tmp *= -1;
	while (++i < length)
	{
		if (n < 0)
			str[length - i] = tmp - (tmp / 10) * 10 + '0';
		else
			str[length - i - 1] = tmp - (tmp / 10) * 10 + '0';
		tmp /= 10;
	}
	str[length] = '\0';
	return (str);
}
