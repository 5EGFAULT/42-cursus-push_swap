/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:00 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_push *push)
{
	t_d_list	*tmp;

	if (ft_d_lstsize(push->b) == 0)
		return ;
	tmp = ft_d_lstnew(push->b->content);
	ft_d_lstadd_front(&(push->a), tmp);
	ft_d_lstdelfront(&(push->b));
	print_instruction(PA);
}

void	ft_pb(t_push *push)
{
	t_d_list	*tmp;

	if (ft_d_lstsize(push->a) == 0)
		return ;
	tmp = ft_d_lstnew(push->a->content);
	ft_d_lstadd_front(&(push->b), tmp);
	ft_d_lstdelfront(&(push->a));
	print_instruction(PB);
}
