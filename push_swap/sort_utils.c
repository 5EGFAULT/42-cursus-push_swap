/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:05:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 10:08:49 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	get_max(t_d_list *s, long max)
{
	int	i;
	int	x;
	int	j;

	if (!s)
		return (0);
	i = s->content;
	j = 0;
	x = 0;
	s = s->next;
	while (s)
	{
		if (i < s->content && max > s->content)
		{
			i = s->content;
			x = j;
		}
		s = s->next;
		j++;
	}
	return (i);
}

int	get_closer(int upper, int lower, t_d_list *s)
{
	int	p;
	int	rupper;
	int	rlower;

	p = ft_d_lstsize(s) / 2;
	if (lower < p)
		rlower = lower;
	else
		rlower = ft_d_lstsize(s) - lower;
	if (upper < p)
		rupper = upper;
	else
		rupper = ft_d_lstsize(s) - upper;
	if (upper < 0)
		return (1);
	else if (lower < 0)
		return (0);
	if (rupper < rlower)
		return (0);
	else
		return (1);
}
