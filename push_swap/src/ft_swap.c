/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:23 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/05 21:10:07 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_push *push)
{
	t_d_list	*tmp1;
	t_d_list	*tmp2;

	if (ft_d_lstsize(push->a) <= 1)
		return ;
	tmp1 = push->a;
	tmp2 = push->a->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	push->a = tmp2;
}

void	ft_sb(t_push *push)
{
	t_d_list	*tmp1;
	t_d_list	*tmp2;

	if (ft_d_lstsize(push->b) <= 1)
		return ;
	tmp1 = push->b;
	tmp2 = push->b->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	push->b = tmp2;
}

void	ft_ss(t_push *push)
{
	ft_sa(push);
	ft_sb(push);
}
