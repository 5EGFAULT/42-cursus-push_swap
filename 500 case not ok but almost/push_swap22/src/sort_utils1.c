/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:32:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 19:51:28 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_closer(int i, int i1, t_d_list *s)
{
	int	p;
	int	r;
	int	r1;

	p = ft_d_lstsize(s) / 2;
	if (i1 < p)
		r1 = i1;
	else
		r1 = ft_d_lstsize(s) - i1;
	if (i < p)
		r = i;
	else
		r = ft_d_lstsize(s) - i;
	if (i < 0)
		return (1);
	else if (i1 < 0)
		return (0);
	if (r < r1)
		return (0);
	else
		return (1);
}

int	add_to_a(t_push *push, int i)
{
	int	p;	

	p = ft_d_lstsize(push->b) / 2;
	if (i == 1)
	{
		ft_sb(push);
		ft_pa(push);
		if (push->a->content > push->a->next->content)
			ft_sa(push);
		return (1);
	}
	else if (i == 0)
	{
		ft_pa(push);
		if (push->a->content > push->a->next->content)
			ft_sa(push);
		return (1);
	}
	else if (i < p)
		ft_rb(push);
	else
		ft_rrb(push);
	return (0);
}

int	get_max_2(t_d_list *s, int max)
{
	int	i;

	if (!s)
		return (0);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i < s->content && max > s->content)
			i = s->content;
		s = s->next;
	}
	return (i);
}
