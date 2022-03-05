/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:08 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/05 21:39:20 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rra(t_push *push)
{
	t_d_list	*last;
	t_d_list	*tmp;

	if (push->a && push->a->next)
	{
		last = ft_d_lstlast(push->a);
		tmp = push->a;
		push->a = tmp->next;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}

void	ft_rrb(t_push *push)
{
	t_d_list	*last;
	t_d_list	*tmp;

	if (push->b && push->b->next)
	{
		last = ft_d_lstlast(push->b);
		tmp = push->b;
		push->b = tmp->next;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}

void	ft_rrr(t_push *push)
{
	ft_rra(push);
	ft_rrb(push);
}
