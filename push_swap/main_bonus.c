/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:51:26 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/14 09:10:38 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_push		*push;

	if (argc <= 1)
		return (0);
	push = malloc(sizeof(t_push));
	if (!push)
		return (1);
	push->a = NULL;
	push->b = NULL;
	init_push(argc, argv, push);
	sort(push);
	if (is_sorted(push->a) && ft_d_lstsize(push->b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_d_lstclear(&(push->a));
	ft_d_lstclear(&(push->b));
	free(push);
	return (0);
}
