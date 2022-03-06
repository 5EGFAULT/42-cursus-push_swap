/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_d_list_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:10:17 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/06 10:38:55 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_d_lstdelone(t_d_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_d_lstclear(t_d_list **lst, void (*del)(void*))
{
	t_d_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_d_lstdelone(tmp, del);
	}
}

void	ft_d_lstiter(t_d_list *lst, void (*f)(void *))
{
	t_d_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

t_d_list	*ft_d_lstmap(t_d_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_d_list	*new;
	t_d_list	*tmp;
	t_d_list	*tmp_new;

	tmp = lst;
	(void)del;
	tmp_new = NULL;
	if (tmp)
		tmp_new = ft_d_lstnew(f(tmp->content));
	new = tmp_new;
	while (tmp)
	{
		tmp_new->next = ft_d_lstnew(f(tmp->content));
		tmp_new = tmp_new->next;
		tmp = tmp->next;
	}
	return (new);
}

void	ft_d_lstdelfront(t_d_list **lst, void (*del)(void*))
{
	t_d_list	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	ft_d_lstdelone(tmp, del);
}
