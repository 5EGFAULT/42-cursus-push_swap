/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:25:10 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 14:15:48 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void f(void	*s){
	printf("%d\n",*(int *)s);
}

int	main(int argc, char **argv)
{
	t_push		*push;

	push = malloc(sizeof(t_push));
	if (!push)
		return 1;
	push->a = NULL;
	push->b = NULL;
	init_push(argc, argv, push);
	//char 	**ss;
	int		i;
	
	i =  ft_atoi(argv[1]);
	printf("%d \n", i);
	//ss = ft_split(argv[1], ' ');
	//i = 0;
	//while (ss && ss[i])
	//{
	//	printf("%s \n", ss[i]);
	//	i++;
	//}
	
	return (0);
}
