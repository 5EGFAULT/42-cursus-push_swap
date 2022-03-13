/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 13:30:24 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push *push)
{
	if (ft_d_lstsize(push->a) == 2)
		ft_sa(push);
	else if (ft_d_lstsize(push->a) == 3)
		sort_3(push);
	else if (ft_d_lstsize(push->a) < 10)
		sort_10(push);
	else
	{
		if (ft_d_lstsize(push->a) <= 100)
			sort_over(push, 12);
		else
		{
			sort_over(push, 30);
		}
	}
	print_instruction(NO);
}

void	put_to_b(t_push *push, int s, int *k)
{
	int	j;
	int	v;
	int	i1;
	int	i2;

	j = ft_d_lstsize(push->a) - 1;
	i1 = j / 2 - s;
	i2 = j / 2 + s;
	while (i2 < j && i1 > 0)
	{
		v = s * 2;
		while (v)
		{
			if (push->a->content >= k[i1] && push->a->content < k[i2] && v--)
			{
				ft_pb(push);
				if (ft_d_lstsize(push->b) > 1 && push->b->content < k[j / 2])
					ft_rb(push);
			}
			else
				ft_ra(push);
		}
		i1 -= s;
		i2 += s;
	}
}

void	sort_over(t_push *push, int s)
{
	int	j;
	int	*k;

	k = sort_stack_k(push->a);
	j = ft_d_lstsize(push->a) - 1;
	put_to_b(push, s, k);
	while (push->a)
	{
		ft_pb(push);
		if (push->b->content < k[j / 2])
			ft_rb(push);
	}
	put_to_a(push, k[j], 0);
	free(k);
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

void	sort_10(t_push *push)
{
	int	i;
	int	p;

	while (ft_d_lstsize(push->a) > 3)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_index(push->a, get_min(push->a));
		if (i == 1)
		{
			ft_sa(push);
			ft_pb(push);
		}
		else if (i == 0)
			ft_pb(push);
		else if (i < p)
			ft_ra(push);
		else
			ft_rra(push);
	}
	sort_3(push);
	while (ft_d_lstsize(push->b))
		ft_pa(push);
}
