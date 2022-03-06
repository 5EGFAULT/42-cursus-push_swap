/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 19:41:34 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//static short	cmp(t_d_list *x, t_d_list *y)
//{
//	if (!y)
//		return (2);
//	if (x->content && y->content && *((int *)x->content) < *((int *)y->content))
//		return (1);
//	return (0);
//}

static int	get_index(t_d_list *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (n == *(int *) s->content)
			return i;
		s = s->next;
		i++;
	}
	return i;
}

static int	get_min(t_d_list *s)
{
	int	i;

	if (!s)
		return (0);
	i = *(int *) s->content;
	s = s->next;
	while (s)
	{
		if (i > *(int *) s->content)
			i = *(int *) s->content;
		s = s->next;
	}
	return (i);
}

void	sort(t_push *push)
{
	int		i;
	int		idx;
	int		prox;

	i = 1;
	while (ft_d_lstsize(push->a) > 0)
	{
		while (get_index(push->a,get_min(push->a)))
		{
			i = get_min(push->a);
			prox = ft_d_lstsize(push->a);
			idx = get_index(push->a,i);
			if (idx > prox)
			{
				ft_ra(push);
			}
			else
			{
				ft_rra(push);
			}
		}
		ft_pb(push);
	}
	while (ft_d_lstsize(push->b) > 0)
	{
		ft_pa(push);
	}
	

	print_instruction(NO);
}
