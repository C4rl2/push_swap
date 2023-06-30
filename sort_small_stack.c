/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:08:32 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/30 19:06:33 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_2(t_push_swap *a_list)
{
	if (a_list->value > a_list->next->value)
		sa(a_list);
	else
		return ;
}

void	sort_stack_3(t_push_swap **a_list)
{
	if ((*a_list)->value < (*a_list)->next->value
		&& (*a_list)->next->value < (*a_list)->next->next->value)
		return ;
	else if ((*a_list)->next->value < (*a_list)->value
		&& (*a_list)->next->value > (*a_list)->next->next->value)
	{
		ra(a_list);
		sa(*a_list);
	}
	else if ((*a_list)->next->next->value < (*a_list)->next->value
		&& (*a_list)->next->next->value > (*a_list)->value)
	{
		sa(*a_list);
		ra(a_list);
	}
	else if ((*a_list)->value > (*a_list)->next->next->value
		&& (*a_list)->value < (*a_list)->next->value)
		rra(a_list);
	else if ((*a_list)->value > (*a_list)->next->value
		&& (*a_list)->value < (*a_list)->next->next->value)
		sa(*a_list);
	else if ((*a_list)->next->next->value < (*a_list)->value
		&& (*a_list)->next->next->value > (*a_list)->next->value)
		ra(a_list);
}

void	sort_stack_4(t_push_swap **a_list, t_push_swap **b_list)
{
	int			smallest;
	int			i;
	int			i2;
	t_push_swap	*tmp;

	(norme(), i = 1, i2 = 0, tmp = *a_list, smallest = tmp->value);
	while (tmp->next != NULL)
	{
		i2++;
		if (tmp->next->value < smallest)
		{
			smallest = tmp->next->value;
			i = i2;
		}
		tmp = tmp->next;
	}
	while ((*a_list)->value != smallest)
	{
		if (i < 3)
			ra(a_list);
		else
			rra(a_list);
	}
	pb(a_list, b_list);
	detect4or5(a_list, b_list);
}

void	detect4or5(t_push_swap **a_list, t_push_swap **b_list)
{
	if (ft_lstsize(*a_list) == 3)
	{
		sort_stack_3(a_list);
		pa(a_list, b_list);
	}
	else
		sort_stack_5(a_list, b_list);
}

void	sort_stack_5(t_push_swap **a_list, t_push_swap **b_list)
{
	int			i;
	int			i2;
	int			small;
	t_push_swap	*tmp2;

	(norme(), i = 1, i2 = 0, tmp2 = *a_list, small = tmp2->value);
	while (tmp2->next != NULL)
	{
		i2++;
		if (tmp2->next->value < small)
		{
			small = tmp2->next->value;
			i = i2;
		}
		tmp2 = tmp2->next;
	}
	while ((*a_list)->value != small)
	{
		if (i < 3)
			ra(a_list);
		else
			rra(a_list);
	}
	finish_it(a_list, b_list);
}
