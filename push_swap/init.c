/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:50:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 16:46:24 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_push(int count, char **value, t_push *push)
{
	char	**splited;
	int		i;
	int		j;

	i = 0;
	while (++i < count)
	{
		splited = ft_split(value[i], ' ');
		j = -1;
		while (splited && splited[++j])
			ft_d_lstadd_back(&(push->a), ft_d_lstnew(ft_atoi(splited[j])));
		free_splited(splited);
	}
	check_duplicate(push->a);
	return (1);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	check_duplicate(t_d_list *s)
{
	int			i;
	t_d_list	*tmp1;
	t_d_list	*tmp2;

	tmp1 = s;
	i = 0;
	while (tmp1)
	{
		tmp2 = s;
		i = 0;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
				i++;
			if (i > 1)
				error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
