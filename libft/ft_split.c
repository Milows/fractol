/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:38:54 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/16 04:10:25 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != c)
			s++;
	}
	return (word_count);
}

char	*extract_words(const char *s, char c)
{
	char	*word;
	int		word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	word[word_len] = '\0';
	while (word_len--)
		word[word_len] = s[word_len];
	return (word);
}

char	**fill_split(char **split, const char *s, int words, char c)
{
	int	i;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		split[i] = extract_words(s, c);
		if (!split[i])
		{
			while (i >= 0)
				free(split[i--]);
			free(split);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = fill_split(split, s, words, c);
	return (split);
}
