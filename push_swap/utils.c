/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:46:33 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/12 22:32:20 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splited(char **s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		free(s[i]);
	free(s);
}

static void	put_str(short inst)
{
	if (inst == NO)
		return ;
	if (inst == SA)
		ft_putstr_fd("sa\n", 1);
	if (inst == SB)
		ft_putstr_fd("sb\n", 1);
	if (inst == SS)
		ft_putstr_fd("ss\n", 1);
	if (inst == PA)
		ft_putstr_fd("pa\n", 1);
	if (inst == PB)
		ft_putstr_fd("pb\n", 1);
	if (inst == RA)
		ft_putstr_fd("ra\n", 1);
	if (inst == RB)
		ft_putstr_fd("rb\n", 1);
	if (inst == RR)
		ft_putstr_fd("rr\n", 1);
	if (inst == RRA)
		ft_putstr_fd("rra\n", 1);
	if (inst == RRB)
		ft_putstr_fd("rrb\n", 1);
	if (inst == RRR)
		ft_putstr_fd("rrr\n", 1);
}

void	print_instruction(short inst)
{
	static short	p_inst = NO;

	if ((inst == SA && p_inst == SB) || (inst == SB && p_inst == SA))
	{
			p_inst = SS;
			inst = NO;
	}
	else if ((inst == RA && p_inst == RB) || (inst == RB && p_inst == RA))
	{
			p_inst = RR;
			inst = NO;
	}
	else if ((inst == RRA && p_inst == RRB) || (inst == RRB && p_inst == RRA))
	{
			p_inst = RRR;
			inst = NO;
	}
	put_str(p_inst);
	p_inst = inst;
}

int	add_to_a(int i, t_push *push)
{
	int	p;

	if (ft_d_lstsize(push->a) >= 2 && (i == 1 || i == 0))
		if (push->a->content > push->a->next->content)
			ft_sa(push);
	p = ft_d_lstsize(push->b) / 2;
	if (i == 0)
	{
		ft_pa(push);
		return (1);
	}
	else if (i == 1)
	{
		ft_sb(push);
		ft_pa(push);
		return (1);
	}
	else if (i < p)
		ft_rb(push);
	else
		ft_rrb(push);
	return (0);
}

void	put_to_a(t_push *push, int max, int uppermax)
{
	int	upper;
	int	lower;
	int	n;

	n = 1;
	while (push->b)
	{
		uppermax = get_max(push->b, max + 1L);
		upper = get_index(push->b, uppermax);
		lower = get_index(push->b, get_max(push->b, uppermax));
		if (upper < 0 && lower < 0)
			break ;
		if (n && get_closer(upper, lower, push->b))
		{
			if (add_to_a(lower, push))
				n = 0;
		}
		else
		{
			if (add_to_a(upper, push))
				n = 1;
		}
	}
	if (ft_d_lstsize(push->a) >= 2 && push->a->content > push->a->next->content)
		ft_sa(push);
}
