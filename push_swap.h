/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:28:26 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/01 20:09:40 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ERRDBL "Duplicates in the numbers passed as arguments.\n"
# define ERRLTR "Non-numbers in the arguments.\n"
# define ERRMXMN "Limits of an int not respected.\n"
# define ERRTMN "too much arguments, max 500 numbers\n"
# define ERRSPLIT "Empty double quotes.\n"

typedef struct s_push_swap
{
	int					index;
	int					value;
	char				*str;
	struct s_push_swap	*next;
}	t_push_swap;

//PARSING
int			ft_strlen(char *s);
int			duplicates(t_push_swap *a_list, t_push_swap *list);
int			ft_lstsize(t_push_swap *lst);
int			first_parse(char **av);
char		*ft_strdup(char *s1);
char		**ft_split(char *s, char c);
void		norme(void);
void		delone(t_push_swap *lst);
void		parse_dq(t_push_swap *list);
void		error_msg(char *str, t_push_swap *list, t_push_swap *a_list);
void		finish_it(t_push_swap **a_list, t_push_swap **b_list);
void		print_list(t_push_swap *list);
void		clear_list(t_push_swap **list);
void		detect4or5(t_push_swap **a_list, t_push_swap **b_list);
void		ft_putstr_fd(char *s, int fd);
void		clear_a_list(t_push_swap **list);
t_push_swap	*fill_list(int ac, char **av);
t_push_swap	*final_fill(t_push_swap *list);
t_push_swap	*ft_lstnewa(int value);
t_push_swap	*ft_lstadd_back(t_push_swap **lst, t_push_swap *new);
void		ft_lstadd_front(t_push_swap **lst, t_push_swap *new);
//moves
void		sa(t_push_swap *a_list);
void		sb(t_push_swap *b_list);
void		ss(t_push_swap *a_list, t_push_swap *b_list);
void		pa(t_push_swap **a_list, t_push_swap **b_list);
void		pb(t_push_swap **a_list, t_push_swap **b_list);
void		ra(t_push_swap **a_list);
void		rb(t_push_swap **b_list);
void		rr(t_push_swap **a_list, t_push_swap **b_list);
void		rra(t_push_swap **a_list);
void		rrb(t_push_swap **b_list);
void		rrr(t_push_swap **a_list, t_push_swap **b_list);
void		ft_push_swap(t_push_swap *a_list);
//sort small stack
void		sort_stack_2(t_push_swap *a_list);
void		sort_stack_3(t_push_swap **a_list);
void		sort_stack_4(t_push_swap **a_list, t_push_swap **b_list);
void		sort_stack_5(t_push_swap **a_list, t_push_swap **b_list);
//sort big stack
void		minimum(t_push_swap **a_list);
void		sort_stack_500(t_push_swap **a_list, t_push_swap **b_list);
int			is_a_sorted(t_push_swap **a_list);

#endif