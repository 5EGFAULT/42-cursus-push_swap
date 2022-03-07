/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/07 17:45:28 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//static int	get_index(t_d_list *s, int n)
//{
//	int	i;

//	i = 0;
//	while (s)
//	{
//		if (n == *(int *) s->content)
//			return i;
//		s = s->next;
//		i++;
//	}
//	return i;
//}

void	sort_3(t_push *push)
{
	int	a0;
	int	a1;
	int	a2;

	if (ft_d_lstsize(push->a) == 3)
	{
		a0 = push->a->content;
		a1 = push->a->next->content;
		a2 = push->a->next->next->content;
		if (a0 > a1 && a1 < a2 && a0 < a2)
		{
			ft_sa(push);
			return ;
		}
		if (a0 > a1 && a1 > a2)
		{
			ft_sa(push);
			ft_rra(push);
			return ;
		}
		if (a0 > a1 && a1 < a2 && a0 > a2)
		{
			ft_ra(push);
			return ;
		}
		if (a0 < a1 && a1 > a2 && a0 < a2)
		{
			ft_sa(push);
			ft_ra(push);
			return ;
		}
		if (a0 < a1 && a1 > a2 && a0 > a2)
		{
			ft_rra(push);
			return ;
		}
	}
}


//static int	get_min(t_d_list *s)
//{
//	int	i;

//	if (!s)
//		return (0);
//	i = *(int *) s->content;
//	s = s->next;
//	while (s)
//	{
//		if (i > *(int *) s->content)
//			i = *(int *) s->content;
//		s = s->next;
//	}
//	return (i);
//}

void	sort(t_push *push)
{
	sort_3(push);
	print_instruction(NO);
}
