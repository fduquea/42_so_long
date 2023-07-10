/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:36 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/05 15:39:15 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: split string, with specified character as delimiter, into an array
**			of strings
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter. The array must be
**	ended by a NULL pointer.
*/

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int		count;
	int		i;
	int		old_i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] != c)
				break ;
			i++;
		}
		old_i = i;
		while (s[i])
		{
			if (s[i] == c)
				break ;
			i++;
		}
		if (old_i < i)
			count++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**ar;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ar = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!ar)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ar[j++] = ft_substr(s + i, 0, ft_strclen(s + i, c));
			if (!ar[j - 1])
				return (NULL);
			i += ft_strlen(ar[j - 1]);
		}
	}
	ar[j] = NULL;
	return (ar);
}
