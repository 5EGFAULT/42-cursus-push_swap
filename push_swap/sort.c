/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/12 14:33:02 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_d_list *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (n == s->content)
			return (i);
		s = s->next;
		i++;
	}
	return (i);
}

//int	get_at_index(t_d_list *s, int n)
//{
//	int	i;

//	i = 0;
//	while (s)
//	{
//		if (n == i)
//			return (s->content);
//		s = s->next;
//		i++;
//	}
//	return (i);
//}

int	get_min(t_d_list *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i > s->content)
			i = s->content;
		s = s->next;
	}
	return (i);
}

void	sort(t_push *push)
{
	if (ft_d_lstsize(push->a) == 2)
		ft_sa(push);
	else if (ft_d_lstsize(push->a) == 3)
		sort_3(push);
	else if (ft_d_lstsize(push->a) < 10)
		sort_10(push);
	else if (ft_d_lstsize(push->a) <= 100)
		sort_100(push);
	else
	{
		sort_101(push);
	}
	print_instruction(NO);
}
