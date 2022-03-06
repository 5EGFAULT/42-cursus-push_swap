/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:50:40 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 15:24:28 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_push *push)
{
	(void)push;
}

void	init_push(int count, char **value, t_push *push)
{
	(void)push;
	(void)count;
	(void)value;
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
