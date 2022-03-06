/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:30:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:35:30 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief print a string in file descriptor
 *
 * @param s string to print in file descriptor fd 
 * @param fd  file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s && s[++i])
		write (fd, s + i, 1);
}
