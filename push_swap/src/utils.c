/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:46:33 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:42:10 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_int(void *content)
{
	free(content);
}

void	*clone_int(void *content)
{
	int		*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (NULL);
	*tmp = (*(int *)content);
	return (tmp);
}

void	*new_int(int content)
{
	int		*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (NULL);
	*tmp = content;
	return (tmp);
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
