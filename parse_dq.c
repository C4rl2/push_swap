/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:09:48 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/30 18:57:29 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *str)
{
	int				i;
	long long int	nb;
	int				neg;

	neg = 0;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-nb);
	else
		return (nb);
}

int	secure_atoi(char *s, t_push_swap *list, t_push_swap *a_list)
{
	if (ft_atoi(s) < INT_MIN)
		error_msg(ERRMXMN, list, a_list);
	else if (ft_atoi(s) > INT_MAX)
		error_msg(ERRMXMN, list, a_list);
	return (ft_atoi(s));
}

char	*clean_str(char *s, t_push_swap *list, t_push_swap *a_list)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = 0;
	new_s = malloc(sizeof(char) * (ft_strlen(s) + 1)); //leaks
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == 32 || s[i] == '-')
		{
			new_s[j] = s[i];
			i++;
			j++;
		}
		else
		{
			clear_list(&a_list);
			error_msg(ERRLTR, 0, list);
		}	
	}
	new_s[j] = '\0';
	return (new_s);
}

t_push_swap	*fill_a(char *tmp, t_push_swap *a_list, t_push_swap *list)
{
	int		i;
	int		value;
	char	**tmp_tab;

	tmp_tab = NULL;
	i = 0;
	tmp_tab = ft_split(tmp, ' ');
	if (!tmp_tab)
		error_msg(ERRSPLIT, list, NULL);
	while (tmp_tab[i])
	{
		value = secure_atoi(tmp_tab[i], a_list, list);
		ft_lstadd_back(&a_list, ft_lstnewa(value));
		i++;
	}
	i = -1;
	while (tmp_tab[++i])
		free(tmp_tab[i]);
	free(tmp_tab);
	return (a_list);
}

t_push_swap	*final_fill(t_push_swap *list)
{
	int			i;
	char		*tmp;
	t_push_swap	*tmp_list;
	t_push_swap	*a_list;

	tmp = NULL;
	a_list = NULL;
	i = 0;
	tmp_list = list;
	while (tmp_list)
	{
		tmp = clean_str(tmp_list->str, list, a_list);
		a_list = fill_a(tmp, a_list, list);
		tmp_list = tmp_list->next;
		free(tmp);
		i++;
	}
	// clear_list(&list);
	return (a_list);
}
