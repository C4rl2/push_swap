/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:38:16 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/30 19:53:22 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*list;
	t_push_swap	*a_list;

	list = NULL;
	a_list = NULL;
	if (ac >= 2)
	{
		first_parse(av);
		list = fill_list(ac, av);
		a_list = final_fill(list);
		if (duplicates(a_list, list))
		{
			ft_push_swap(a_list);
			// system("leaks push_swap");
			// exit(1);
		}
	}
	// system("leaks push_swap");
	// exit(1);
	error_msg(0, a_list, 0);
	return (0);
}
