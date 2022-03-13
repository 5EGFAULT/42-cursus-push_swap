/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:05:16 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 14:55:24 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	sort_inter(t_push *push, char *inst)
{
	if (ft_strncmp("ss\n", inst, 5) == 0)
	{
		ft_sa(push);
		ft_sb(push);
	}
	else if (ft_strncmp("rr\n", inst, 5) == 0)
	{
		ft_ra(push);
		ft_rb(push);
	}
	else if (ft_strncmp("rrr\n", inst, 5) == 0)
	{
		ft_rra(push);
		ft_rrb(push);
	}
	else
		error();
}

void	sort(t_push *push)
{
	int	i;
	char	*s;

	(void)push;
	i = -1;
	s = get_next_line(0);
	while (s)
	{
		if (ft_strncmp("\n", s, 2) == 0)
			break ;
		else if (ft_strncmp("sa\n", s, 5) == 0)
			ft_sa(push);
		else if (ft_strncmp("sb\n", s, 5) == 0)
			ft_sb(push);
		else if (ft_strncmp("ra\n", s, 5) == 0)
			ft_ra(push);
		else if (ft_strncmp("rb\n", s, 5) == 0)
			ft_rb(push);
		else if (ft_strncmp("pa\n", s, 5) == 0)
			ft_pa(push);
		else if (ft_strncmp("pb\n", s, 5) == 0)
			ft_pb(push);
		else if (ft_strncmp("rra\n", s, 5) == 0)
			ft_rra(push);
		else if (ft_strncmp("rrb\n", s, 5) == 0)
			ft_rrb(push);
		else 
			sort_inter(push, s);
		free(s);
		s = get_next_line(0);
	}
	if (s)
		free(s);
}