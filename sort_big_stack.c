/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:37:40 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/03 12:18:29 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_lst(t_push_swap **a_list)
{
	t_push_swap	*min;
	t_push_swap	*tmp;
	static int	index = 0;

	(norme(), tmp = *a_list, min = *a_list);
	while (tmp)
	{
		if (tmp->index == -1)
			min = tmp;
		tmp = tmp->next;
	}
	if (min->index != -1)
		return ;
	tmp = *a_list;
	while (tmp)
	{
		if (tmp->value < min->value && tmp->index == -1)
			min = tmp;
		tmp = tmp->next;
	}
	min->index = index++;
	return (index_lst(a_list));
}

int	is_a_sorted(t_push_swap **a_list)
{
	t_push_swap	*tmp;

	tmp = *a_list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

void	sort(t_push_swap **a_list, t_push_swap **b_list)
{
	int			bit;
	int			size_a;

	bit = 0;
	size_a = ft_lstsize(*a_list);
	while (bit <= 8 && (is_a_sorted(a_list) == 0))
	{
		while (size_a--)
		{
			if ((((*a_list)->index >> bit) & 1) != 0)
				ra(a_list);
			else
				pb(a_list, b_list);
		}
		while (ft_lstsize(*b_list) > 0)
			pa(a_list, b_list);
		bit++;
		size_a = ft_lstsize(*a_list);
	}
}

void	sort_stack_500(t_push_swap **a_list, t_push_swap **b_list)
{
	index_lst(a_list);
	sort(a_list, b_list);
}
