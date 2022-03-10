/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:32:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 20:10:32 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_instructions(t_push *push, int value)
{
	int inst;
	int i;
	int i_t;
	int i_b;

	inst = 1;
	i_t = get_index(push->b, value);
	i_b = get_index(push->b, value);
	i = 0;
	while (i_b++ < ft_d_lstsize(push->b) && i_t++ >= 0)
		inst++;
	return (inst + get_min_inst_set_a(push, value));
}

int	get_min_inst_set_a(t_push *push, int value)
{
	int inst;
	int f;
	int b;

	inst = 0;
	f = -1;
	b = ft_d_lstsize(push->a);
	if (get_at_index(0) > value && get_at_index(b - 1) < value)
		return (0);
	if (get_at_index(0) < value && get_at_index(b - 1) > value)
		return (0);
	while (f++ < --b && ((get_at_index(f) < value && get_at_index(f + 1) > value)||( get_at_index(b - 1) < value && get_at_index(b) > value)))
		inst++;
	return (inst);
}
