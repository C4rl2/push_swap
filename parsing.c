/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:27:47 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/03 12:20:35 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *str, t_push_swap *list, t_push_swap *a_list)
{
	if (list)
		clear_list(&list);
	if (a_list)
		clear_a_list(&a_list);
	if (str != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
	}
	exit(1);
}

void	clear_list(t_push_swap **list)
{
	t_push_swap	*tmp;
	t_push_swap	*to_del;

	tmp = *list;
	if (*list == NULL)
		return ;
	while (tmp != NULL)
	{
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	*list = NULL;
}

void	clear_a_list(t_push_swap **list)
{
	t_push_swap	*tmp;
	t_push_swap	*next;

	tmp = *list;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = next;
	}
	*list = NULL;
}

int	first_parse(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] < 48 || av[j][i] > 57) && av[j][i] != '-'
				&& av[j][i] != '"' && av[j][i] != '\'' && av[j][i] != 32)
				error_msg(ERRLTR, 0, 0);
			i++;
		}
		j++;
	}
	return (0);
}

int	duplicates(t_push_swap *a_list, t_push_swap *list)
{
	t_push_swap	*tmp;
	t_push_swap	*begina;

	begina = a_list;
	while (a_list)
	{
		tmp = a_list;
		while (tmp->next != NULL)
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			if (a_list->value == tmp->value)
				error_msg(ERRDBL, list, a_list);
		}
		a_list = a_list->next;
	}
	a_list = begina;
	clear_a_list(&list);
	return (1);
}
