/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:32:43 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/10 10:54:39 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define NO		0
# define SA		1
# define SB		2
# define SS		3
# define PA		4
# define PB		5
# define RA		7
# define RB		8
# define RR		9
# define RRA	10
# define RRB	11
# define RRR	12

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

//!			ft_swap.c
void		ft_sa(t_push *push);
void		ft_sb(t_push *push);
//!			ft_push.c
void		ft_pa(t_push *push);
void		ft_pb(t_push *push);
//!			ft_rotate.c
void		ft_ra(t_push *push);
void		ft_rb(t_push *push);
//!			ft_reverse_rotate.c
void		ft_rra(t_push *push);
void		ft_rrb(t_push *push);
//!			utils.c
void		free_splited(char **s);
void		print_instruction(short inst);
//!			libft0.c
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
//!			libft1.c
int			ft_atoi(const char *str);
void		cmpsacks(t_push *push);
//!			init.c
void		init_push(int count, char **value, t_push *push);
void		init_stack(t_push *push);
void		error(void);
void		print_content(int s);
void		check_duplicate(t_d_list *s);
//!			sort.c
void		sort(t_push *push);
void		sort_3(t_push *push);
void		sort_10(t_push *push);
void		sort_100(t_push *push);
int			is_sorted(t_d_list *s);	
int			get_index(t_d_list *s, int n);
int			get_min(t_d_list *s);
int			get_less(t_d_list *s, int n, int n2);
int			get_max(t_d_list *s);
void		sort_left_over(t_push *push, int n);
void		put_back_to_a(t_push *push);
int			*sort_stack_k(t_d_list *s);
void		sort_101(t_push *push);
void		push_to_b_all_under_n_and_n2(t_push *push, int n, int n2, int n3);

int			get_closer(int i, int i1, t_d_list *s);
int			add_to_a(t_push *push, int i, int n);
void		ad_to_b(int i, int r, t_push *push);
int			get_max_2(t_d_list *s, int max);
int			get_min_2(t_d_list *s, int min);

#endif