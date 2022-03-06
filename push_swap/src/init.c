/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:50:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 17:38:22 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_push(int count, char **value, t_push *push)
{
	char	**splited;
	int		i;
	int		j;
	int		*n;

	i = 0;
	while (++i < count)
	{
		splited = ft_split(value[i], ' ');
		j = -1;
		while (splited[++j])
		{
			n = new_int(ft_atoi(splited[j]));
			ft_d_lstadd_front(&(push->a), ft_d_lstnew(n));
		}
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	print_content(void	*s)
{
	printf("%d\n",*(int *)s);
}
