/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:42:00 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void f(void	*s){
	printf("%d\n",*(int *)s);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_d_list	*a;
	t_d_list	*b;
	t_d_list	*c;
	t_d_list	*d;
	t_d_list	*x;
	t_d_list	*y;
	t_push		*push;

	a = ft_d_lstnew(new_int(5));
	b = ft_d_lstnew(new_int(15));
	c = ft_d_lstnew(new_int(25));
	d = ft_d_lstnew(new_int(35));
	x = NULL;
	y = NULL;
	//ft_d_lstiter(a, f);
	ft_d_lstadd_front(&x, a);
	ft_d_lstadd_front(&y, b);

	ft_d_lstadd_front(&y, c);
	ft_d_lstadd_front(&y, d);

	//ft_d_lstadd_back(&x, a);
	//ft_d_lstadd_back(&a, b);
	//ft_d_lstadd_back(&a, c);
	//ft_d_lstadd_back(&a, d);
	//ft_d_lstiter(x, f);
	
	push = malloc(sizeof(t_push));
	if (!push)
		return 1;
	push->a = x;
	push->b = y;
	//ft_d_lstiter(push->b, f);
	////printf("\n");
	////ft_d_lstiter(push->b, f);
	//printf("\n\n");
	//ft_rrb(push);
	//ft_rb(push);
	//ft_d_lstiter(push->b, f);
	//printf("\n");
	////ft_d_lstiter(push->b, f);

	//print_instruction(SB);
	print_instruction(NO);
	//print_instruction(SS);
	//print_instruction(SS);
	return (0);
}
