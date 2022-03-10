/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:05:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_left_over(t_push *push, int n)
{
	int	p;
	int	i;
	int	i1;
	int	r;

	r = 1;
	while (ft_d_lstsize(push->a) > 3)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_index(push->a, get_min(push->a));
		i1 = get_index(push->a, get_min_2(push->a, get_min(push->a)));
		//if (r && get_closer(i, i1, push->a))
		//{
		//	if (i1 == 1)
		//	{
		//		ft_sa(push);
		//		ft_pb(push);
		//		r = 0;
		//	}
		//	else if (i1 == 0)
		//	{
		//		ft_pb(push);
		//		r = 0;
		//	}
		//	else if (i1 < p)
		//		ft_ra(push);
		//	else
		//		ft_rra(push);
		//}
		//else
		//{
			if (i == 1)
			{
				ft_sa(push);
				//if (push->b->content < push->b->next->content)
				//	ft_sb(push);
				ft_pb(push);
				r = 1;
			}
			else if (i == 0)
			{
				//if (push->b->content < push->b->next->content)
				//	ft_sb(push);
				ft_pb(push);
				r = 1;
			}
			else if (i < p)
				ft_ra(push);
			else
				ft_rra(push);
		}
	//}
	//if (push->b->content > push->b->next->content)
	//	ft_sb(push);
	sort_3(push);
	if (ft_d_lstsize(push->a) == 2 && push->a->content > push->a->next->content)
		ft_sa(push);
	(void)n;
	while (ft_d_lstsize(push->b) > n)
		ft_pa(push);
}

void	put_back_to_a(t_push *push)
{
	int	i;
	int	i1;
	int	n;
	int	p;

	n = 1;
	while (ft_d_lstsize(push->b))
	{
		p = ft_d_lstsize(push->b) / 2;
		i = get_index(push->b, get_max(push->b));
		i1 = get_index(push->b, get_max_2(push->b, get_max(push->b)));
		if (get_closer(i, i1, push->b) && n)
		{
			if(add_to_a(push, i1, n))
				n = 0;
		}
		else{
			if(add_to_a(push, i, n))
				n = 1;
		}
	}
	if (push->a->content > push->a->next->content)
		ft_sa(push);
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

void	ad_to_b(int i, int r, t_push *push)
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
		if (r && ft_d_lstsize(push->b) >=2 && push->b->content < push->b->next->content)
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

void	push_to_b_all_under_n_and_n2(t_push *push, int n, int n2, int n3)
{
	int	i;
	int	i1;
	int	p;

	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_less(push->a, n, n3);
		i1 = get_less(push->a, n2, n);
		if (i < 0 && i1 < 0)
			break ;
		if (get_closer(i, i1, push->a))
			ad_to_b(i1, 1, push);
		else
			ad_to_b(i, 0, push);
	}
}
