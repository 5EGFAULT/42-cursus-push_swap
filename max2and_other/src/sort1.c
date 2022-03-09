/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 19:36:13 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_to_b_all_under_n_and_n3(t_push *push, int n, int n2, int n3)
{
	int	i;
	int	i1;
	int	p;
	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i1 = get_less(push->a, n2, n3);
		i = get_less(push->a, n3, n);
		if (i < 0 && i1 < 0)
			break ;
		if (get_closer(i, i1, push->a))
			ad_to_b(i1, 1, push);
		else
			ad_to_b(i, 0, push);
	}
}

void	sort_100(t_push *push)
{
	int	k_nbr;
	int	*k;
	//int	i;

	//i = 0;
	k = sort_stack_k(push->a);
	k_nbr = ft_d_lstsize(push->a) / 9;
	push_to_b_all_under_n_and_n2(push, k[k_nbr], k[k_nbr * 2], k[0]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 3], k[k_nbr * 4], k[2]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 5], k[k_nbr * 6], k[4]);
	push_to_b_all_under_n_and_n2(push, k[k_nbr * 7], k[k_nbr * 8], k[6]);
	
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 5], k[k_nbr * 4] + 1);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 6], k[k_nbr * 4]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 1], k[k_nbr * 7], k[k_nbr * 4]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 4]);
	//while (++i < 9 / 2)
	//{
	//		//print_content(k_nbr * i);
	//		//print_content(k_nbr * (8 - i));
	//		push_to_b_all_under_n_and_n3(push, k[k_nbr * i], k[k_nbr * (8 - i)], k[9 / 2]);
	//}
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
