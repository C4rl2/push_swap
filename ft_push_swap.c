/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:30:04 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/03 12:06:06 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norme(void)
{
}

int	ft_lstsize(t_push_swap *lst)
{
	int			i;
	t_push_swap	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	finish_it(t_push_swap **a_list, t_push_swap **b_list)
{
	pb(a_list, b_list);
	sort_stack_3(a_list);
	pa(a_list, b_list);
	pa(a_list, b_list);
}

void	ft_push_swap(t_push_swap *a_list)
{
	t_push_swap	*b_list;

	b_list = NULL;
	if (is_a_sorted(&a_list) != 1)
	{
		if (ft_lstsize(a_list) == 1)
			return ;
		else if (ft_lstsize(a_list) == 2)
			sort_stack_2(a_list);
		else if (ft_lstsize(a_list) == 3)
			sort_stack_3(&a_list);
		else if (ft_lstsize(a_list) <= 5)
			sort_stack_4(&a_list, &b_list);
		else if (ft_lstsize(a_list) <= 500)
			sort_stack_500(&a_list, &b_list);
		else
			error_msg(ERRTMN, a_list, 0);
		error_msg(0, a_list, 0);
	}
	else
		error_msg(0, a_list, 0);
}
