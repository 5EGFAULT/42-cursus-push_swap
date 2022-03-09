/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:30:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/09 20:26:57 by asouinia         ###   ########.fr       */
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

int	get_less(t_d_list *s, int n, int n2)
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
		if (n >= front->content && n2 <= front->content)
			return (i_f);
		front = front->next;
		back = back->prev;
		i_b--;
		i_f++;
	}
	return (-1);
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
	else
	{
		sort_101(push);
	}
	print_instruction(NO);
}
