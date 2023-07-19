/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:57:52 by wonlim            #+#    #+#             */
/*   Updated: 2022/07/15 21:56:32 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_table(char **table, int index)
{
	int	i;

	i = 0;
	while (i < index && index != -1)
	{
		free(table[i]);
		i++;
	}
	free(table);
	return (0);
}

int	get_word_count(const char *str, char c)
{
	int	count;

	if (c == '\0')
		return (1);
	count = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str != c && *str)
			str++;
		count++;
		while (*str == c)
			str++;
	}
	return (count);
}

int	init_words(char **words, const char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		count = 0;
		while (str[count] != c && str[count] != '\0')
			count++;
		words[i] = (char *)malloc(sizeof(char) * (count + 1));
		if (!words[i])
			return (free_table(words, i));
		j = 0;
		while (*str != c && *str != '\0')
			words[i][j++] = *str++;
		words[i++][j] = '\0';
	}
	words[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	int		check;

	if (!s)
		return (0);
	count = get_word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (0);
	count = 0;
	check = init_words(words, s, c);
	if (!check)
		return (0);
	return (words);
}
