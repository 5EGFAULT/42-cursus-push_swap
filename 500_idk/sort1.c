/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/12 18:14:03 by asouinia         ###   ########.fr       */
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

int	is_sorted_l_h(t_d_list *s, int low, int high)
{
	int	i;
	int	j;

	if (!s)
		return (1);
	j = -1;
	while (++j < low)
		s = s->next;
	
	i = s->content;
	while (s && j++ <= high)
	{
		if (i > s->content)
			return (0);
		i = s->content;
		s = s->next;
	}
	return (1);
}

int	is_sorted_l_h_b(t_d_list *s, int low, int high)
{
	int	i;
	int	j;

	if (!s)
		return (1);
	j = -1;
	while (++j < low)
		s = s->next;
	
	i = s->content;
	while (s && j++ <= high)
	{
		if (i < s->content)
			return (0);
		i = s->content;
		s = s->next;
	}
	return (1);
}

int	get_at_index(t_d_list *s, int idx)
{
	int	i;

	if (!s)
		exit(1);
	i = 0;
	while (s && i++ < idx)
		s = s->next;
	return (s->content);
}

int	get_pivot(int *k, int max, int min)
{
	int	i;
	int	j;

	i = -1;
	while (k[++i] != min)
		;
	j = -1;
	while (k[++j] != max)
		;
	if (max == min)
	{
		return (max);
	} 
	return (k[(j + i) / 2]);
}

void q_500_b(t_push *push, int *k, int low, int high)
{
	int	rotate;
	int	start;
	int	p;

	(void)low;
	if (high < ft_d_lstsize(push->b)  && 0 < high && !is_sorted_l_h_b(push->b, 0, high))
	{
		if (ft_d_lstsize(push->b) == 2)
			ft_sb(push);
		else
		{
			rotate = 0;
			start = 0;
			p = get_pivot(k, get_max(push->b, 2147483648), get_min(push->b)) ;
			while (start++ < high)
			{
				if (push->b->content < p)
				{
					ft_pa(push);
				}
				else
				{
					ft_rb(push);
					rotate++;
				}
			}
			//while (start-- && rotate--)
			//{
			//	ft_rra(push);
			//}
			//q_500(push, k, 0, ft_d_lstsize(push->a) - 1);	
		}
	}
}

void q_500(t_push *push, int *k, int low, int high)
{
	int	rotate;
	int	start;
	int	p;

	(void)low;
	if (high < ft_d_lstsize(push->a)  && 0 < high && !is_sorted_l_h(push->a, 0, high))
	{
		if (ft_d_lstsize(push->a) == 2)
			ft_sa(push);
		else
		{
			rotate = 0;
			start = 0;
			p = get_pivot(k, get_max(push->a, get_at_index(push->a, high)), get_min(push->a)) ;
			while (start++ < high)
			{
				if (push->a->content < p)
				{
					ft_pb(push);
				}
				else
				{
					ft_ra(push);
					rotate++;
				}
			}
			//while (start-- && rotate--)
			//{
			//	ft_rra(push);
			//}
			//q_500_b(push, k, 0, ft_d_lstsize(push->b) - 1);	
			q_500(push, k, 0, ft_d_lstsize(push->a) - 1);	
		}
	}
}

void put_to_b_101(t_push *push, long max, long min, int mid)
{
	//int	upper;
	//int	lower;

	//while (push->a)
	//{
	//	upper = get_between(push->a, mid, max);
	//	//lower = get_between(push->a, min, mid);
	//	if (upper < 0 )
	//		break ;
	//	//if (get_closer(upper , lower, push->a))
	//	//	add_to_b(lower, 0, push);
	//	//else
	//		add_to_b(upper, 1, push);
	//}
	//while (push->a)
	//{
	//	upper = get_between(push->a, mid, max);
	//	lower = get_between(push->a, min, mid);
	//	if (lower < 0)
	//		break ;
	//	if (get_closer(upper , lower, push->a))
	//		add_to_b(lower, 0, push);
	//	else
	//		add_to_b(upper, 1, push);
	//}
	int	rr = 58;
	while (rr > 0 && push->a)
	{
		if (push->a->content >= min && push->a->content < max)
		{
			rr--;
			ft_pb(push);
			if (push->b->content < mid && ft_d_lstsize(push->b) > 1)
				ft_rb(push);
		}
		else
			ft_ra(push);
	}
}

void	sort_101(t_push *push)
{
	int	*k;
	int s;
	int j;
	int v;
	int i1;
	int i2;

	k = sort_stack_k(push->a);
	s = 30;
	j = ft_d_lstsize(push->a) - 1;
	//printf("\n | %d  | \n\n", get_at_index(push->a, j));
	//q_500(push, k, 0, j);
	//while (j / 2 + s < j && j / 2 - s > 0 )
	//{
	//	put_to_b_101(push, k[j / 2 + s], k[j / 2 - s], k[j / 2]);
	//	s += s;
	//}
	//put_to_b_101(push, k[j] + 1L, k[0] - 1L, k[j / 2]);
	i1 = j / 2 - s;
	i2 = j /2 + s;
	while (i2 < j && i1  > 0)
	{
		v = 60;
		while (v)
		{
			if (push->a->content >= k[i1] && push->a->content < k[i2])
			{
				v--;
				ft_pb(push);
				if (ft_d_lstsize(push->b) > 1 && push->b->content < k[j / 2])
					ft_rb(push);
				//if (push->b->content < k[j / 2])
			}
			else
				ft_ra(push);
		}
		//s +=s; 
		i1 -= s;
		i2 += s;
	}

	while (push->a)
	{
		ft_pb(push);
		//if (push->b->content < k[j / 2] && ft_d_lstsize(push->b) > 1)
		if (push->b->content < k[j / 2])
			ft_rb(push);
	}

	//put_to_b(push, k[j], k[0], k[j / 2]);
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