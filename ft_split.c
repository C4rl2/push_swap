/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafraixe <cafraixe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:18:04 by cafraixe          #+#    #+#             */
/*   Updated: 2023/06/21 19:26:33 by cafraixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		end;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (len < ft_strlen(s))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (str);
	end = start + len;
	while (start < end && s[start])
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

int	ft_count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

int	ft_start_word(char *s, char c, int word)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] != c)
		{
			if (count == word)
				break ;
			count++;
			while (s[i] && s[i] != c)
					i++;
		}
	}
	return (i);
}

int	ft_len_word(char *s, char c, int word)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] != c)
		{
			if (count == word)
			{
				while (s[i + len] && s[i + len] != c)
					len++;
				break ;
			}
			count++;
			while (s[i] && s[i] != c)
					i++;
		}
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		start;
	int		len;

	words = ft_count_words(s, c);
	i = 0;
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (words == 0)
	{
		tab = NULL;
		return (tab);
	}
	while (i < words)
	{
		start = ft_start_word(s, c, i);
		len = ft_len_word(s, c, i);
		tab[i] = ft_substr(s, start, len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
