/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:06:15 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/14 17:59:51 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char *s, int i, char c)
{
	int	wordcount;

	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			wordcount++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (wordcount);
}

static int	size_word(char *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}
static char	ft_free(char **matrix, int j)
{
	while (j-- > 0)
		free(matrix[j]);
	free(matrix);
	return (NULL);
}
char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wordcounts;
	int		size;
	char	**matrix;

	wordcounts = wordcount(s, i, c);
	j = -1;
	i = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * (wordcounts + 1))))
		return (NULL);
	while (j++ < wordcounts)
	{
		while (s[i] == c)
			i++;
		size = size_word(s, i, c);
		if (!(matrix[j] = ft_substr(s, i, size)))
			;
		{
			ft_free(matrix, j);
			return (NULL);
		}
		i = i + size;
	}
	matrix[j] = 0;
	return (matrix);
}
