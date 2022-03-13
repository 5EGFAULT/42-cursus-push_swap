/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:49:49 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 15:52:06 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line_bonus.h"

typedef struct s_d_list
{
	int				content;
	struct s_d_list	*next;
	struct s_d_list	*prev;
}				t_d_list;
typedef struct s_push
{
	t_d_list	*a;
	t_d_list	*b;

}				t_push;
//!			s_d_list_0.c
t_d_list	*ft_d_lstnew(int content);
void		ft_d_lstadd_front(t_d_list **lst, t_d_list *new);
int			ft_d_lstsize(t_d_list *lst);
t_d_list	*ft_d_lstlast(t_d_list *lst);
void		ft_d_lstadd_back(t_d_list **lst, t_d_list *new);
//!			s_d_list_1.c
void		ft_d_lstdelone(t_d_list *lst);
void		ft_d_lstclear(t_d_list **lst);
void		ft_d_lstiter(t_d_list *lst, void (*f)(int));
void		ft_d_lstdelfront(t_d_list **lst);
void		ft_d_lstiter_back(t_d_list *lst, void (*f)(int));
//!			ft_rotate_ft_swap_bonus.c
void		ft_sa(t_push *push);
void		ft_sb(t_push *push);
void		ft_ra(t_push *push);
void		ft_rb(t_push *push);
//!			ft_reverse_rotate_ft_push_bonus.c
void		ft_rra(t_push *push);
void		ft_rrb(t_push *push);
void		ft_pa(t_push *push);
void		ft_pb(t_push *push);
//!			libft0.c
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
//!			libft1.c
int			ft_atoi(const char *str);
//!			init.c
void		init_push(int count, char **value, t_push *push);
void		init_stack(t_push *push);
void		error(void);
void		check_duplicate(t_d_list *s);
//!			sort_utils.c
int			is_sorted(t_d_list *s);

void		sort(t_push *push);
#endif