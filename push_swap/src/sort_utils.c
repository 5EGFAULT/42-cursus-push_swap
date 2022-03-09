/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:05:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 14:51:24 by asouinia         ###   ########.fr       */
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

int	ad_to_a(int i, t_push *push)
{
	int	p;
	int	a1;

	a1 = push->a->content;
	p = ft_d_lstsize(push->b) / 2;
	if (i == 1)
	{
		if (push->a->content > push->a->next->content)
			ft_sa(push);
		ft_sb(push);
		ft_pa(push);
		if (push->a->content > push->a->next->content)
			ft_sa(push);
	}
	else if (i == 0)
	{
		if (push->a->content > push->a->next->content)
			ft_sa(push);
		ft_pa(push);
		if (push->a->content > push->a->next->content)
			ft_sa(push);
	}
	else if (i < p)
		ft_rb(push);
	else
		ft_rrb(push);
	if (a1 != push->a->content)
		return (1);
	return (0);
}

void	put_back_to_a(t_push *push, int n)
{
	int	i;
	int	p;
	int	i1;
	int	r;

	n = 0;
	while (ft_d_lstsize(push->b))
	{
		p = ft_d_lstsize(push->b) / 2;
		i = get_index(push->b, get_max(push->b));
		i1 = get_index(push->b, get_max_2(push->b, get_max(push->b)));
		if (i < 0 && i1 < 0)
			break ;
		else if (i1 < p)
			r = i1;
		else
			r = ft_d_lstsize(push->b) - i1;
		if (n)
		{
			if (ad_to_a(i, push))
				n = 0;
		}
		else if (i < 0)
		{
			if (ad_to_a(i1, push))
				n = 1;
		}
		else if (i1 < 0)
		{
			if (ad_to_a(i, push))
				n = 0;
		}
		else if (i < p)
		{
			if (i < r)
			{
				if (ad_to_a(i, push))
					n = 0;
			}
			else
			{
				if (ad_to_a(i1, push))
					n = 1;
			}		
		}
		else
		{
			if (ft_d_lstsize(push->a) - i < r)
			{
				if (ad_to_a(i, push))
					n = 0;
			}
			else
			{
				if (ad_to_a(i1, push))
					n = 1;
			}
		}
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

void	ad_to_b(int	i, int r , t_push *push)
{
	int	p;

	p = ft_d_lstsize(push->a) / 2;
	if (i == 0)
	{
		ft_pb(push);
		if (r)
			ft_rb(push);
	}
	else if (i == 1)
	{
		ft_sa(push);
		ft_pb(push);
		if (!r)
			ft_rb(push);
	}
	else if (i < p)
		ft_ra(push);
	else
		ft_rra(push);
}

void	push_to_b_all_under_n_and_n2(t_push *push, int n, int n2, int n3)
{
	int	i;
	int	i1;
	int	p;
	int	r;

	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_less_2(push->a, n, n3);
		i1 = get_less_2(push->a, n2, n);
		if (i < 0 && i1 < 0)
			break ;
		if (i1 < p)
			r = i1;
		else
			r = ft_d_lstsize(push->a) - i1;
		if (i < 0)
			ad_to_b(i1, 1, push);
		else if (i1 < 0)
			ad_to_b(i, 0, push);
		else if (i < p)
		{
			if (i < r)
				ad_to_b(i, 0, push);
			else
				ad_to_b(i1, 1, push);
		}
		else
		{
			if (ft_d_lstsize(push->a) - i < r)
				ad_to_b(i, 0, push);
			else
				ad_to_b(i1, 1, push);
		}
	}	
}

void	push_to_b_all_under_n_and_n3(t_push *push, int n, int n2, int n3)
{
	int	i;
	int	i1;
	int	p;
	int	r;

	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i1 = get_less_2(push->a, n2, n3);
		i = get_less_2(push->a, n3, n);
		if (i < 0 && i1 < 0)
			break ;
		if (i1 < p)
			r = i1;
		else
			r = ft_d_lstsize(push->a) - i1;
		if (i < 0)
			ad_to_b(i1, 1, push);
		else if (i1 < 0)
			ad_to_b(i, 0, push);
		else if (i < p)
		{
			if (i < r)
				ad_to_b(i, 0, push);
			else
				ad_to_b(i1, 1, push);
		}
		else
		{
			if (ft_d_lstsize(push->a) - i < r)
				ad_to_b(i, 0, push);
			else
				ad_to_b(i1, 1, push);
		}
	}	
}
