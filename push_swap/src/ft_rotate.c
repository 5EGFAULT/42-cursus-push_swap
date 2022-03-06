/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:17 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:43:05 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_push *push)
{
	t_d_list	*last;

	if (push->a && push->a->next)
	{
		last = ft_d_lstlast(push->a);
		if (last->prev)
			last->prev->next = NULL;
		last->next = push->a;
		push->a->prev = last;
		last->prev = NULL;
		push->a = last;
	}
	print_instruction(RA);
}

void	ft_rb(t_push *push)
{
	t_d_list	*last;

	if (push->b && push->b->next)
	{
		last = ft_d_lstlast(push->b);
		if (last->prev)
			last->prev->next = NULL;
		last->next = push->b;
		push->b->prev = last;
		last->prev = NULL;
		push->b = last;
	}
	print_instruction(RB);
}