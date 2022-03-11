/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:32:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/11 17:26:39 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_push *push, int low, int high)
{
	int	pivot;
	int start;
	int rotate;

	if (high <= low)
		return ;
	rotate = 0;
	//print_content(high - low - 1);
	start = low;
	if (!is_sorted_l_h(push->a, low, high))
	{
		while (start++ < high)
		{		
			pivot = (get_at_index(push->a, low + start) + get_at_index(push->a, high - start)) / 2;
			if (push->a->content < pivot)
			{
				ft_pb(push);
			}
			else
			{
				//ft_pb(push);
				ft_ra(push);
				rotate++;
			}
		}
	}
	//while (start-- > low && rotate--)
	//	ft_rrb(push);
	a_to_b(push, low, high - rotate - 1 );
	//b_to_a(push, 0, ft_d_lstsize(push->b) - 1);
}

void	b_to_a(t_push *push, int low, int high)
{
	int	pivot;
	int start;
	int rotate;

	if (high <= low)
		return ;
	rotate = 0;
	pivot = (get_at_index(push->b, low) + get_at_index(push->b, high)) / 2;
	//print_content(high - low - 1);
	start = low;
	if (!is_sorted_l_h(push->b, low, high))
	{
		while (start++ < high)
		{
			if (push->b->content > pivot)
			{
				ft_pa(push);
			}
			else
			{
				//ft_pa(push);
				ft_rb(push);
				rotate++;
			}
		}
	}
	//while (start-- > low && rotate--)
	//	ft_rra(push);
	//a_to_b(push, start, high);
	//b_to_a(push, 0, start);
	b_to_a(push, 0, high - rotate - 1 );
	a_to_b(push, 0 , ft_d_lstsize(push->a) - 1);
}

int			is_sorted_l_h(t_d_list *s, int low, int high)
{
	int	i;
	int	idx;

	if (!s)
		return (1);
	idx = -1;
	while (++idx < low)
	{
		i = s->content;
		s = s->next;
	}
	while (s && idx < high)
	{
		if (i > s->content)
			return (0);
		i = s->content;
		s = s->next;
	}
	return (1);
}

int	get_min_l_h(t_d_list *s, int low, int high)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	j = 0;
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