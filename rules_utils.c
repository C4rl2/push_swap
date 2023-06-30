/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:06:36 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/18 15:53:03 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delone(t_push_swap *lst)
{
	t_push_swap	*next;

	if (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

void	ft_lstadd_front(t_push_swap **lst, t_push_swap *new)
{
	new->next = *lst;
		*lst = new;
}
