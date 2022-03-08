/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/08 16:20:33 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_index(t_d_list *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (n == s->content)
			return (i);
		s = s->next;
		i++;
	}
	return (i);
}

int	get_min(t_d_list *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i > s->content)
			i = s->content;
		s = s->next;
	}
	return (i);
}

int	get_max(t_d_list *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i < s->content)
			i = s->content;
		s = s->next;
	}
	return (i);
}

int	get_less(t_d_list *s, int n)
{
	int			i_b;
	int			i_f;
	t_d_list	*front;
	t_d_list	*back;

	if (!s)
		exit(2);
	i_f = 0;
	i_b = ft_d_lstsize(s) - 1;
	back = ft_d_lstlast(s);
	front = s;
	while (back && front && front->prev != back)
	{
		if (n > front->content)
			return (i_f);
		if (n > back->content)
			return (i_b);
		front = front->next;
		back = back->prev;
		i_b--;
		i_f++;
	}
	return (-1);
}

void	push_to_b_all_under_n(t_push *push, int n)
{
	int	i;
	int	p;
	
	while (1)
	{
		p = ft_d_lstsize(push->a) / 2;
		i = get_less(push->a, n);
		if (i < 0)
			break ;
		if (i == 1)
		{
			ft_sa(push);
			ft_pb(push);
		}
		else if (i == 0)
			ft_pb(push);
		else if (i < p)
			ft_ra(push);
		else
			ft_rra(push);
	}	
}

void	sort(t_push *push)
{
	if (ft_d_lstsize(push->a) == 2)
		ft_sa(push);
	else if (ft_d_lstsize(push->a) == 3)
		sort_3(push);
	else if (ft_d_lstsize(push->a) < 10)
		sort_10(push);
	else if (ft_d_lstsize(push->a) <= 100)
		sort_100(push);
	print_instruction(NO);
}

int	is_sorted(t_d_list *s)
{
	int	i;

	if (!s)
		return (1);
	i = s->content;
	s = s->next;
	while (s)
	{
		if (i > s->content)
			return (0);
		i = s->content;
		s = s->next;
	}
	return (1);
}
