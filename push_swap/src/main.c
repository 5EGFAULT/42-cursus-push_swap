/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/07 21:08:51 by asouinia         ###   ########.fr       */
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
	if (is_sorted(push->a))
		return 0;
	//ft_d_lstiter(push->a, print_content);
	//ft_d_lstiter_back(push->a, print_content);
	//cmpsacks(push);
	//ft_ra(push);
	//ft_d_lstiter_back(push->a, print_content);
	//ft_pa(push);
	//ft_pb(push);
	//ft_d_lstiter(push->a, print_content);
	sort(push);
//printf("\nAfter\n\n");
	//ft_sa(push);
	//ft_ra(push);
	////printf("\n");
	////print_instruction(NO);
	//ft_d_lstiter(push->a, print_content);
	//cmpsacks(push);
	//printf("\n-------------AAAAAAAAA------\n");
	//printf("\n-------------BBBBBB------\n");
	//ft_d_lstiter(push->b, print_content);
	return (0);
}
