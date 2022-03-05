/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:32:43 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/05 21:08:21 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../src/libft/libft.h"
# include <stdio.h>
typedef struct s_d_list
{
	void			*content;
	struct s_d_list	*next;
	struct s_d_list	*prev;
}				t_d_list;
typedef struct s_push
{
	t_d_list	*a;
	t_d_list	*b;

}				t_push;
t_d_list	*ft_d_lstnew(void *content);
void		ft_d_lstadd_front(t_d_list **lst, t_d_list *new);
int			ft_d_lstsize(t_d_list *lst);
t_d_list	*ft_d_lstlast(t_d_list *lst);
void		ft_d_lstadd_back(t_d_list **lst, t_d_list *new);
void		ft_d_lstdelone(t_d_list *lst, void (*del)(void*));
void		ft_d_lstclear(t_d_list **lst, void (*del)(void*));
void		ft_d_lstiter(t_d_list *lst, void (*f)(void *));
t_d_list	*ft_d_lstmap(t_d_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_d_lstdelfront(t_d_list **lst, void (*del)(void*));

void		ft_sa(t_push *push);
void		ft_sb(t_push *push);
void		ft_ss(t_push *push);
void		ft_pa(t_push *push);
void		ft_pb(t_push *push);
void		ft_ra(t_push *push);
void		ft_rb(t_push *push);
void		ft_rr(t_push *push);
void		ft_rra(t_push *push);
void		ft_rrb(t_push *push);
void		ft_rrr(t_push *push);

void		free_int(void *content);
void		*clone_int(void *content);
void		*new_int(int content);

#endif