/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:05:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/08 18:11:03 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_left_over(t_push *push, int n)
{
	int	p;
	int	i;

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
	if (ft_d_lstsize(push->a) == 2 && push->a->content > push->a->next->content)
		ft_sa(push);
	while (ft_d_lstsize(push->b) > n)
		ft_pa(push);
}

void	put_back_to_a(t_push *push)
{
	int	i;
	int	p;

	while (ft_d_lstsize(push->b))
	{
		p = ft_d_lstsize(push->b) / 2;
		i = get_index(push->b, get_max(push->b));
		if (i == 1)
		{
			ft_sb(push);
			ft_pa(push);
		}
		else if (i == 0)
			ft_pa(push);
		else if (i < p)
			ft_rb(push);
		else
			ft_rrb(push);
	}
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

void	push_to_b_all_under_n(t_push *push, int n)
{
	int	i;
	int	p;

	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_less(push->a, n);
		if (i < 0)
			break ;
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
}
