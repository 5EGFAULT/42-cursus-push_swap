/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:34:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 21:25:27 by asouinia         ###   ########.fr       */
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
	k_nbr = (ft_d_lstsize(push->a) - 1) / 8;
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 5], k[k_nbr * 4]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 6], k[k_nbr * 4]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 7], k[k_nbr * 4]);
	push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 4]);
	sort_left_over(push, k_nbr * 8);
	put_back_to_a(push);
}

void	sort_101(t_push *push)
{
	int	k_nbr;
	int	*k;

	k = sort_stack_k(push->a);
	//k_nbr = ft_d_lstsize(push->a) / 15;
	//push_to_b_all_under_n_and_n2(push, k[k_nbr], k[k_nbr * 2], k[0]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 3], k[k_nbr * 4], k[2]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 5], k[k_nbr * 6], k[4]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 7], k[k_nbr * 8], k[6]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 9], k[k_nbr * 10], k[8]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 11], k[k_nbr * 12], k[10]);
	//push_to_b_all_under_n_and_n2(push, k[k_nbr * 13], k[k_nbr * 14], k[12]);

	//k_nbr = (ft_d_lstsize(push->a) - 1) / 14;
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 6], k[k_nbr * 8], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 5], k[k_nbr * 9], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 4], k[k_nbr * 10], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 11], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 12], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 13], k[k_nbr * 7]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 7]);
	//sort_left_over(push, k_nbr * 14);

	//k_nbr = (ft_d_lstsize(push->a) - 1) / 12;
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 5], k[k_nbr * 7], k[k_nbr * 6]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 4], k[k_nbr * 8], k[k_nbr * 6]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 9], k[k_nbr * 6]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 10], k[k_nbr * 6]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 11], k[k_nbr * 6]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 6]);
	//sort_left_over(push, k_nbr * 12);
	
	//k_nbr = (ft_d_lstsize(push->a) - 1) / 18;
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 8], k[k_nbr * 10], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 7], k[k_nbr * 11], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 6], k[k_nbr * 12], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 5], k[k_nbr * 13], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 4], k[k_nbr * 14], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 15], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 16], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 17], k[k_nbr * 9]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 9]);
	//sort_left_over(push, k_nbr * 18);

	k_nbr = (ft_d_lstsize(push->a) - 1) / 16;
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 7], k[k_nbr * 9], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 6], k[k_nbr * 10], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 5], k[k_nbr * 11], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 4], k[k_nbr * 12], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 13], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 14], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 15], k[k_nbr * 8]);
	push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 8]);
	sort_left_over(push, k_nbr * 16);


	//k_nbr = (ft_d_lstsize(push->a) - 1) / 24;
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 11], k[k_nbr * 13], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 10], k[k_nbr * 14], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 9], k[k_nbr * 15], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 8], k[k_nbr * 16], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 7], k[k_nbr * 17], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 6], k[k_nbr * 18], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 5], k[k_nbr * 19], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 4], k[k_nbr * 20], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 21], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 22], k[k_nbr * 12]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 23], k[k_nbr * 16]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 13]);
	//sort_left_over(push, k_nbr * 24);

	//k_nbr = (ft_d_lstsize(push->a) - 1) / 8;
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 3], k[k_nbr * 5], k[k_nbr * 4]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr * 2], k[k_nbr * 6], k[k_nbr * 4]);
	//push_to_b_all_under_n_and_n3(push, k[k_nbr], k[k_nbr * 7], k[k_nbr * 4]);
	//push_to_b_all_under_n_and_n3(push, k[0], k[ft_d_lstsize(push->a) - 1], k[k_nbr * 4]);
	//sort_left_over(push, k_nbr * 8);
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
