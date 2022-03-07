/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:12:41 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/07 21:44:52 by asouinia         ###   ########.fr       */
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

void	cmpsacks(t_push *push)
{
	t_d_list	*t1;
	t_d_list	*t2;

	t1 = push->a;
	t2 = push->b;
	system("clear");
	printf("\n");
	printf("\tA\t|");
	printf("\tB\t|\n");
	while (t1 || t2)
	{
		if (t1)
			printf("\t%d\t|", (t1->content));
		else
			printf("\t\t\t|");
		if (t2)
			printf("\t%d\t|\n", (t2->content));
		else
			printf("\t\t|\n");
		if (t1)
			t1 = t1->next;
		if (t2)
			t2 = t2->next;
	}
	system("read -n 1 -s -p \"Press any key to continue...\"" );
}
