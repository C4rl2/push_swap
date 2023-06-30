/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:06:42 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/30 19:03:37 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap **a_list)
{
	t_push_swap	*node;
	t_push_swap *tmp;

	node = NULL;
	node = *a_list;
	(*a_list) = (*a_list)->next;
	node->next = NULL;
	tmp = (*a_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap **b_list)
{
	t_push_swap	*node;
	t_push_swap *tmp;

	node = NULL;
	node = *b_list;
	(*b_list) = (*b_list)->next;
	node->next = NULL;
	tmp = (*b_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_push_swap **a_list)
{
	t_push_swap	*tmp;
	t_push_swap	*node;

	node = NULL;
	tmp = *a_list;
	while (tmp->next != NULL)
	{
		node = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a_list;
	*a_list = tmp;
	node->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push_swap **b_list)
{
	t_push_swap	*tmp;
	t_push_swap	*node;

	node = NULL;
	tmp = *b_list;
	while (tmp->next != NULL)
	{
		node = tmp;
		tmp = tmp->next;
	}
	tmp->next = *b_list;
	*b_list = tmp;
	node->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}
