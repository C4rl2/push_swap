/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:01:11 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/01 18:22:41 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_push_swap **a_list, t_push_swap **b_list)
{
	t_push_swap	*node;
	t_push_swap	*tmp;
	t_push_swap	*node2;
	t_push_swap	*tmp2;

	node = NULL;
	node = *a_list;
	(*a_list) = (*a_list)->next;
	node->next = NULL;
	tmp = (*a_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node2 = NULL;
	node2 = *b_list;
	(*b_list) = (*b_list)->next;
	node2->next = NULL;
	tmp2 = (*b_list);
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = node2;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_push_swap **a_list, t_push_swap **b_list)
{
	t_push_swap	*tmp;
	t_push_swap	*node;
	t_push_swap	*tmp2;
	t_push_swap	*node2;

	(norme(), node = NULL, tmp = *a_list);
	while (tmp->next != NULL)
	{
		node = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a_list;
	*a_list = tmp;
	node->next = NULL;
	node2 = NULL;
	tmp2 = *b_list;
	while (tmp2->next != NULL)
	{
		node2 = tmp2;
		tmp2 = tmp2->next;
	}
	tmp2->next = *b_list;
	*b_list = tmp2;
	node2->next = NULL;
	ft_putstr_fd("rrr\n", 1);
}
