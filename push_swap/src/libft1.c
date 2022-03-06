/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:12:41 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 15:24:03 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	check_ft_atoi_inter(int sign, long nbr, char c)
{
	nbr = nbr * 10 + c - '0';
	if (nbr > 2147483648)
		error();
	if (nbr == 2147483648 && sign > 0)
		error();
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		++i;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[++i] < '0' || str[i] > '9')
			error();
	}
	else if (str[i] < '0' || str[i] > '9')
		error();
	while (str[i] >= '0' && str[i] <= '9')
		nbr = check_ft_atoi_inter(sign, nbr, str[i++]);
	if ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ') || (str[i] == '\0'))
		return (sign * nbr);
	error();
	return (0);
}
