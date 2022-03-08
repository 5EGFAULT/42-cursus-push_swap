/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/08 16:24:03 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_100(t_push *push)
{
	int	k_nbr;
	int	*k;
	int	i;
	int	p;

	k = sort_stack_k(push->a);
	k_nbr = ft_d_lstsize(push->a) / 4;
	//cmpsacks(push);
	//print_content(k_nbr);
	//print_content(ft_d_lstsize(push->a));
	push_to_b_all_under_n(push, k[k_nbr]);
	push_to_b_all_under_n(push, k[k_nbr * 2]);
	push_to_b_all_under_n(push, k[k_nbr * 3]);
	//print_instruction(NO);
	//cmpsacks(push);
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
	while (ft_d_lstsize(push->b) > k_nbr * 3)
		ft_pa(push);
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
	//print_instruction(NO);
	//cmpsacks(push);
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
