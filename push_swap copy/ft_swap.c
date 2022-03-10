/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:23 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
