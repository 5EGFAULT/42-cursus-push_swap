/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/11 22:28:12 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_b(int i, int r, t_push *push)
{
	int	p;

	p = ft_d_lstsize(push->a) / 2;
	if (i == 0)
	{
		ft_pb(push);
		if (!r)
			ft_rb(push);
	}
	else if (i == 1)
	{
		ft_sa(push);
		if (ft_d_lstsize(push->b) >=2 && push->b->content < push->b->next->content)
			ft_sb(push);
		ft_pb(push);
		if (!r)
			ft_rb(push);
 	}
	else if (i < p)
		ft_ra(push);
	else
		ft_rra(push);
}

int	add_to_a(int i, t_push *push)
{
	int	p;

	p = ft_d_lstsize(push->b) / 2;
	if (i == 0)
	{
		if (ft_d_lstsize(push->a) >=2 && push->a->content > push->a->next->content)
			ft_sa(push);
		ft_pa(push);
		return (1);
	}
	else if (i == 1)
	{
		if (ft_d_lstsize(push->a) >=2 && push->a->content > push->a->next->content)
			ft_sa(push);
		ft_sb(push);
		ft_pa(push);
		return (1);
 	}
	else if (i < p)
		ft_rb(push);
	else
		ft_rrb(push);
	return (0);
}

int	get_max(t_d_list *s, long max)
{
	int	i;
	int	x;
	int	j;

	if (!s)
		return (0);
	i = s->content;
	j = 0;
	x = 0;
	s = s->next;
	while (s)
	{
		if (i < s->content && max > s->content)
		{
			i = s->content;
			x = j;
		}
		s = s->next;
		j++;
	}
	return (i);
}

int	get_closer(int upper, int lower, t_d_list *s)
{
	int	p;
	int	rupper;
	int	rlower;

	p = ft_d_lstsize(s) / 2;
	if (lower < p)
		rlower = lower;
	else
		rlower = ft_d_lstsize(s) - lower;
	if (upper < p)
		rupper = upper;
	else
		rupper = ft_d_lstsize(s) - upper;
	if (upper < 0)
		return (1);
	else if (lower < 0)
		return (0);
	if (rupper < rlower)
		return (0);
	else
		return (1);
}

void put_to_a(t_push *push, int max)
{
	int	upper;
	int	lower;
	int	n;

	n = 1;
	while (push->b)
	{
		upper = get_index(push->b, get_max(push->b, max + 1L));
		lower = get_index(push->b, get_max(push->b, get_max(push->b, max + 1L)));
		if (upper < 0 && lower < 0)
			break ;
		if (n && get_closer(upper , lower, push->b))
		{
			if (add_to_a(lower, push))
				n = 0;		
		}
		else
		{
			if (add_to_a(upper, push))
			{
				n = 1;
			}
		}
	}
	if (ft_d_lstsize(push->a) >=2 && push->a->content > push->a->next->content)
		ft_sa(push);
}

int	get_between(t_d_list *front, int min, int max)
{
	int			i_f;

	if (!front)
		exit(2);
	i_f = 0;
	while (front)
	{
		if (max >= front->content && min <= front->content)
			return (i_f);
		front = front->next;
		i_f++;
	}
	return (-1);
}

void put_to_b(t_push *push, int max, int min, int mid)
{
	int	upper;
	int	lower;

	while (push->a)
	{
		upper = get_between(push->a, mid, max);
		lower = get_between(push->a, min, mid);
		if (upper < 0 && lower < 0)
			break ;
		if (get_closer(upper , lower, push->a))
			add_to_b(lower, 0, push);
		else
			add_to_b(upper, 1, push);
	}
}

void	sort_100(t_push *push)
{
	int	*k;
	int s;
	int j;

	k = sort_stack_k(push->a);
	s = 16;
	j = ft_d_lstsize(push->a) - 1;
	while (j / 2 + s < j && j / 2 - s > 0 )
	{
		put_to_b(push, k[j / 2 + s], k[j / 2 - s], k[j / 2]);
		s += s;
	}
	put_to_b(push, k[j], k[0], k[j / 2]);
	put_to_a(push, k[j]);
	free(k);
}

void	sort_101(t_push *push)
{
	int	*k;
	int s;
	int j;

	k = sort_stack_k(push->a);
	s = 30;
	j = ft_d_lstsize(push->a) - 1;
	while (j / 2 + s < j && j / 2 - s > 0 )
	{
		put_to_b(push, k[j / 2 + s], k[j / 2 - s], k[j / 2]);
		s += s;
	}
	put_to_b(push, k[j], k[0], k[j / 2]);
	put_to_a(push, k[j]);
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
