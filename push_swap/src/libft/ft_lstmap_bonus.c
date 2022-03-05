/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:31:45 by asouinia          #+#    #+#             */
/*   Updated: 2021/11/16 00:31:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp_new;

	tmp = lst;
	(void)del;
	tmp_new = NULL;
	if (tmp)
		tmp_new = ft_lstnew(f(tmp->content));
	new = tmp_new;
	while (tmp)
	{
		tmp_new->next = ft_lstnew(f(tmp->content));
		tmp_new = tmp_new->next;
		tmp = tmp->next;
	}
	return (new);
}
