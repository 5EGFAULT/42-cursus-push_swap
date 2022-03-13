/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_d_list_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:10:09 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 16:31:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_d_list	*ft_d_lstnew(int content)
{
	t_d_list	*ret;

	ret = (t_d_list *)malloc(sizeof(t_d_list));
	if (!ret)
		exit(15);
	ret->next = NULL;
	ret->prev = NULL;
	ret->content = content;
	return (ret);
}

void	ft_d_lstadd_front(t_d_list **lst, t_d_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
		*lst = new;
	}
	else
	{
		new->prev = NULL;
		*lst = new;
	}
}

int	ft_d_lstsize(t_d_list *lst)
{
	int			i;
	t_d_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_d_list	*ft_d_lstlast(t_d_list *lst)
{
	t_d_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_d_lstadd_back(t_d_list **lst, t_d_list *new)
{
	t_d_list	*last;

	if (!new)
		exit(15);
	if (*lst)
	{
		last = ft_d_lstlast(*lst);
		new->next = NULL;
		last->next = new;
		new->prev = last;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
	}
}
