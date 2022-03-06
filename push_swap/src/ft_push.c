/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:19:00 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:42:27 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pa(t_push *push)
{
	t_d_list	*tmp;
	void		*tmp_content;

	if (ft_d_lstsize(push->b) == 0)
		return ;
	tmp_content = clone_int(push->b->content);
	tmp = ft_d_lstnew(tmp_content);
	ft_d_lstadd_front(&(push->a), tmp);
	ft_d_lstdelfront(&(push->b), free_int);
	print_instruction(PA);
}

void	ft_pb(t_push *push)
{
	t_d_list	*tmp;
	void		*tmp_content;

	if (ft_d_lstsize(push->a) == 0)
		return ;
	tmp_content = clone_int(push->a->content);
	tmp = ft_d_lstnew(tmp_content);
	ft_d_lstadd_front(&(push->b), tmp);
	ft_d_lstdelfront(&(push->a), free_int);
	print_instruction(PB);
}
