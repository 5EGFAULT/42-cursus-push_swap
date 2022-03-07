/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/07 20:01:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	sort_3(t_push *push)
{
	int	a0;
	int	a1;
	int	a2;

	if (ft_d_lstsize(push->a) != 3)
		return ;
	a0 = push->a->content;
	a1 = push->a->next->content;
	a2 = push->a->next->next->content;
	if (a0 > a1 && a1 < a2 && a0 < a2)
		return (ft_sa(push));
	if (a0 > a1 && a1 > a2)
	{
		ft_sa(push);
		ft_rra(push);
	}
	if (a0 > a1 && a1 < a2 && a0 > a2)
		return (ft_ra(push));
	if (a0 < a1 && a1 > a2 && a0 < a2)
	{
		ft_sa(push);
		ft_ra(push);
	}
	if (a0 < a1 && a1 > a2 && a0 > a2)
		return (ft_rra(push));
}

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
	sort_3(push);
	print_instruction(NO);
}

int	is_sorted(t_d_list *s)
{
	int	i;

	if (!s)
		return (1);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i > s->content)
			return (0);
		i = s->content;
		s = s->next;
	}
	return (1);
}
