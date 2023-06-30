/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:49:03 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/18 15:49:43 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *a_list)
{
	int	tmp;

	if (a_list && a_list->next)
	{
		tmp = a_list->next->value;
		a_list->next->value = a_list->value;
		a_list->value = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_swap *b_list)
{
	int	tmp;

	if (b_list && b_list->next)
	{
		tmp = b_list->next->value;
		b_list->next->value = b_list->value;
		b_list->value = tmp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_swap *a_list, t_push_swap *b_list)
{
	sa(a_list);
	sb(b_list);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_push_swap **a_list, t_push_swap **b_list)
{
	t_push_swap	*tmp;

	tmp = *b_list;
	*b_list = tmp->next;
	tmp->next = *a_list;
	*a_list = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_push_swap **a_list, t_push_swap **b_list)
{
	t_push_swap	*tmp;

	tmp = *a_list;
	*a_list = tmp->next;
	tmp->next = *b_list;
	*b_list = tmp;
	ft_putstr_fd("pb\n", 1);
}
