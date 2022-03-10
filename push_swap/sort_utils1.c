/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:32:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 19:43:50 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_instructions(t_push *push, int value)
{
	int inst;
	int i;

	inst = 0;
	i = get_index(push->b, value);
	while (i >= 1)
	{
	
	}
	
	return (inst + get_min_inst_set_a(push, value));
}

int	get_min_inst_set_a(t_push *push, int value)
{
	int inst;
	int f;
	int b;

	inst = 0;
	f = 0;
	b = ft_d_lstsize(push->a);
	while (i < b && get_at_index(i) < value)
	{
		
	}
	
	return (inst);
}
