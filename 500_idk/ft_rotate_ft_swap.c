/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ft_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:17 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 19:09:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_push *push)
{
	t_d_list	*front;
	t_d_list	*tmp;

	if (ft_d_lstsize(push->a) > 1)
	{
		front = push->a;
		tmp = ft_d_lstnew(front->content);
		ft_d_lstadd_back(&(push->a), tmp);
		front->next->prev = NULL;
		push->a = push->a->next;
		ft_d_lstdelone(front);
		print_instruction(RA);
	}
}

void	ft_rb(t_push *push)
{
	t_d_list	*front;
	t_d_list	*tmp;

	if (ft_d_lstsize(push->b) > 1)
	{
		front = push->b;
		tmp = ft_d_lstnew(front->content);
		ft_d_lstadd_back(&(push->b), tmp);
		front->next->prev = NULL;
		push->b = push->b->next;
		ft_d_lstdelone(front);
		print_instruction(RB);
	}
}

void	ft_sa(t_push *push)
{
	int		tmp1;

	if (ft_d_lstsize(push->a) <= 1)
		return ;
	tmp1 = push->a->content;
	push->a->content = push->a->next->content;
	push->a->next->content = tmp1;
	print_instruction(SA);
}

void	ft_sb(t_push *push)
{
	int		tmp1;

	if (ft_d_lstsize(push->b) <= 1)
		return ;
	tmp1 = push->b->content;
	push->b->content = push->b->next->content;
	push->b->next->content = tmp1;
	print_instruction(SB);
}
