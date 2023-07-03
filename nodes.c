/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:45:01 by cafraixe          #+#    #+#             */
/*   Updated: 2023/07/03 12:20:10 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ft_lstnew(char *s)
{
	t_push_swap	*tmp;

	tmp = malloc(sizeof(t_push_swap));
	if (tmp == NULL)
		return (NULL);
	tmp->index = -1;
	tmp->value = 0;
	tmp->str = s;
	tmp->next = NULL;
	return (tmp);
}

t_push_swap	*ft_lstnewa(int value)
{
	t_push_swap	*tmp;

	tmp = malloc(sizeof(t_push_swap));
	if (tmp == NULL)
		return (NULL);
	tmp->index = -1;
	tmp->value = value;
	tmp->str = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_push_swap	*ft_lstadd_back(t_push_swap **lst, t_push_swap *new)
{
	t_push_swap	*begin;

	if (*lst == NULL)
	{
		(*lst) = new;
		return (*lst);
	}
	begin = *lst;
	while (*lst && (*lst)->next != NULL)
		*lst = (*lst)->next;
	if ((*lst)->next == NULL)
		(*&(*lst))->next = new;
	*lst = begin;
	return (*lst);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_push_swap	*fill_list(int ac, char **av)
{
	int			j;
	t_push_swap	*list;

	list = NULL;
	(void)ac;
	j = 1;
	while (av[j])
	{
		list = ft_lstadd_back(&list, ft_lstnew(ft_strdup(av[j])));
		j++;
	}
	return (list);
}
