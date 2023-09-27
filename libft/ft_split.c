/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:58:04 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/27 21:11:21 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_allocsize(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			n++;
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static char	**ft_free(char **f)
{
	free(f);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	holder;
	char	**split;

	i = 0;
	n = 0;
	split = (char **)malloc(sizeof(char *) * (ft_allocsize(s, c) + 1));
	if (!s || !split)
		ft_free(split);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		holder = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > holder)
		{
			split[n] = ft_substr((s + holder), 0, (i - holder));
			n++;
		}
	}
	split[n] = 0;
	return (split);
}

/*
Description 
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

Return Value 
The array of new strings resulting from the split.
NULL if the allocation fails.
*/