/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:38:27 by oel-bour          #+#    #+#             */
/*   Updated: 2019/10/11 10:38:31 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int i;
	int j;
	int l;

	l = ft_strlen(s);
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0' && s[i + 1] != c)
			j++;
		i++;
	}
	if (l >= 1)
	{
		if (s[0] != c && s[l - 1] != c)
			return (j + 1);
		if (s[0] == c && s[l - 1] == c)
			return (j - 1);
	}
	return (j);
}

static int	*count_max_word(char *s, char c)
{
	int i;
	int x;
	int j;
	int	*m;

	m = (int*)malloc((count(s, c)) * sizeof(int));
	if (m == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		x = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			x++;
		}
		m[j] = x;
		j++;
	}
	return (m);
}

static char	**final(char const *s, char **words, char c, int coun)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (i < coun)
	{
		while (s[j] == c)
			j++;
		x = 0;
		while (s[j] != c && s[j] != '\0')
		{
			words[i][x] = s[j];
			x++;
			j++;
		}
		words[i][x] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}

char		**setfree(char **words, int i)
{
	if (words == NULL)
		return (NULL);
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		coun;
	int		i;
	char	**words;
	int		*m;

	if (s == NULL)
		return (NULL);
	m = count_max_word((char*)s, c);
	coun = count((char*)s, c);
	words = (char**)malloc((coun + 1) * sizeof(char*));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < coun)
	{
		words[i] = (char*)malloc((m[i] + 1) * sizeof(char));
		if (words[i] == NULL)
			return (setfree(words, i));
		i++;
	}
	words[i] = NULL;
	return (final(s, words, c, coun));
}
