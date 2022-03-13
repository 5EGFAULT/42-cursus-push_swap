/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 13:05:15 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push		*push;

	push = malloc(sizeof(t_push));
	if (!push)
		return (1);
	push->a = NULL;
	push->b = NULL;
	//printf("%p\n",push->a);
	init_push(argc, argv, push);
	//printf("%p\n",push->a);
	//printf("%d\n",push->a->content);
	if (is_sorted(push->a))
		return (0);
	sort(push);
	ft_d_lstclear(&(push->a));
	ft_d_lstclear(&(push->b));
	free(push);
	//system("leaks push_swap");
	return (0);
}
