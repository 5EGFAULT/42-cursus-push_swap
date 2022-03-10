/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_d_list_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:10:17 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 18:47:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_d_lstdelone(t_d_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_d_lstclear(t_d_list **lst)
{
	t_d_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_d_lstdelone(tmp);
	}
}

void	ft_d_lstiter(t_d_list *lst, void (*f)(int))
{
	t_d_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_d_lstdelfront(t_d_list **lst)
{
	t_d_list	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	ft_d_lstdelone(tmp);
}

void	ft_d_lstiter_back(t_d_list *lst, void (*f)(int))
{
	t_d_list	*tmp;

	tmp = ft_d_lstlast(lst);
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->prev;
	}
}
