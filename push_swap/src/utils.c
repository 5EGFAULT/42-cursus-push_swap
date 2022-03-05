/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:46:33 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/05 21:59:02 by asouinia         ###   ########.fr       */
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
	*tmp = (*(int*)content);
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

void	print_instruction(char *str)
{
	static char	*old_inst;

	if (!ft_strncmp(str, "sb", 2) && !ft_strncmp(old_inst, "sa", 2)))
	if (!ft_strncmp(str, "rb", 2) && !ft_strncmp(old_inst, "ra", 2)))
	if (!ft_strncmp(str, "rrb", 2) && !ft_strncmp(old_inst, "rra", 2)))
	if (!ft_strncmp(old_inst, "sb", 2) && !ft_strncmp(str, "sa", 2)))
	if (!ft_strncmp(old_inst, "rb", 2) && !ft_strncmp(str, "ra", 2)))
	if (!ft_strncmp(old_inst, "rrb", 2) && !ft_strncmp(str, "rra", 2)))
		

	old_inst = str;
}
