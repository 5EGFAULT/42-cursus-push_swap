/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_ft_push _bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:08 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 13:59:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_push *push)
{
	t_d_list	*last;
	t_d_list	*tmp;

	if (ft_d_lstsize(push->a) > 1)
	{
		last = ft_d_lstlast(push->a);
		tmp = ft_d_lstnew(last->content);
		last->prev->next = NULL;
		tmp->prev = NULL;
		ft_d_lstadd_front(&(push->a), tmp);
		ft_d_lstdelone(last);
	}
}

void	ft_rrb(t_push *push)
{
	t_d_list	*last;
	t_d_list	*tmp;

	if (ft_d_lstsize(push->b) > 1)
	{
		last = ft_d_lstlast(push->b);
		tmp = ft_d_lstnew(last->content);
		last->prev->next = NULL;
		tmp->prev = NULL;
		ft_d_lstadd_front(&(push->b), tmp);
		ft_d_lstdelone(last);
	}
}

void	ft_pa(t_push *push)
{
	t_d_list	*tmp;

	if (ft_d_lstsize(push->b) == 0)
		return ;
	tmp = ft_d_lstnew(push->b->content);
	ft_d_lstadd_front(&(push->a), tmp);
	ft_d_lstdelfront(&(push->b));
}

void	ft_pb(t_push *push)
{
	t_d_list	*tmp;

	if (ft_d_lstsize(push->a) == 0)
		return ;
	tmp = ft_d_lstnew(push->a->content);
	ft_d_lstadd_front(&(push->b), tmp);
	ft_d_lstdelfront(&(push->a));
}
