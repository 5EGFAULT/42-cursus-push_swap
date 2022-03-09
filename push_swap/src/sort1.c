/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 11:07:27 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_100(t_push *push)
{
	int	k_nbr;
	int	*k;

	k = sort_stack_k(push->a);
	k_nbr = ft_d_lstsize(push->a) / 9;
	push_to_b_all_under_n_and_n2(push, k[k_nbr], k[k_nbr * 2], k[0]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 3], k[k_nbr * 4], k[2]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 5], k[k_nbr * 6], k[4]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 7], k[k_nbr * 8], k[6]);
	sort_left_over(push, k_nbr * 8);
	put_back_to_a(push);
}

void	sort_101(t_push *push)
{
	int	k_nbr;
	int	*k;

	k = sort_stack_k(push->a);
	k_nbr = ft_d_lstsize(push->a) / 15;
	push_to_b_all_under_n_and_n2(push, k[k_nbr], k[k_nbr * 2], k[0]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 3], k[k_nbr * 4], k[2]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 5], k[k_nbr * 6], k[4]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 7], k[k_nbr * 8], k[6]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 9], k[k_nbr * 10], k[8]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 11], k[k_nbr * 12], k[10]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 13], k[k_nbr * 14], k[12]);
	sort_left_over(push, k_nbr * 14);
	put_back_to_a(push);
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
