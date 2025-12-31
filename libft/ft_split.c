/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:32:07 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/04 12:24:42 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char	const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*copy_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc (len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**array;
	char	**ptr;

	num_words = count_words(s, c);
	array = malloc((num_words + 1) * (sizeof(char *)));
	if (!array)
		return (NULL);
	ptr = array;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			*ptr = copy_word(s, c);
			while (*s && *s != c)
				s++;
			ptr++;
		}
	}
	*ptr = NULL;
	return (array);
}
