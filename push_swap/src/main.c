/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/08 18:53:20 by asouinia         ###   ########.fr       */
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
		return (0);
	sort(push);
	//system(" read");
	//system(" leaks  push_swap");
	return (0);
}
