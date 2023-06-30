/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:37:40 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/30 11:53:16 by cafraixe         ###   ########.fr       */
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

int	max_bit(t_push_swap **a_list)
{
	int			maxi;
	int			maxb;
	t_push_swap	*tmp;

	(norme(), tmp = *a_list, maxi = tmp->index, maxb = 0);
	while (tmp->next)
	{
		if (tmp->next->index > maxi)
			maxi = tmp->next->index;
		tmp = tmp->next;
	}
	while (maxi >>= 1)
		maxb++;
	return (maxb);
}

void	sort(t_push_swap **a_list, t_push_swap **b_list, int max_bit)
{
	int			bit;
	int			size_a;

	bit = 0;
	size_a = ft_lstsize(*a_list);
	while (bit <= max_bit)
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
	int			size_b;
	int			max_b;
	t_push_swap	*tmp;
	// t_push_swap	*begin = *a_list;

	size_b = 0;
	tmp = *b_list;
	index_lst(a_list);
	max_b = max_bit(a_list);
	sort(a_list, b_list, max_b);
	// print_list(*a_list);
	// printf("bbbb\n");
	// print_list(*b_list);
	// char	c;
	// read(0, &c, 1);
	// while (tmp)
	// {
		
	// 	tmp = tmp->next;
	// }
}