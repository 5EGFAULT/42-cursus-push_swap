/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 17:39:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push		*push;

	push = malloc(sizeof(t_push));
	if (!push)
		return (1);
	push->a = NULL;
	push->b = NULL;
	init_push(argc, argv, push);
	ft_d_lstiter(push->a, print_content);
	printf("\n");
	ft_d_lstiter(push->b, print_content);
	ft_sa(push);
	ft_pb(push);
	print_instruction(NO);
	printf("\n\n");
	ft_d_lstiter(push->a, print_content);
	printf("\n");
	ft_d_lstiter(push->b, print_content);
	return (0);
}
