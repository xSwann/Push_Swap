/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:22:25 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 16:11:29 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill(int start, int end, const char *str, char *chaine)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (i <= end)
	{
		chaine[j] = str[i];
		i++;
		j++;
	}
	chaine[j] = '\0';
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	fill_result(const char *s, char c, char **result)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		m = i;
		while (s[i] && s[i] != c)
			i++;
		if (m < i)
		{
			result[j] = malloc(sizeof(char) * (i - m + 1));
			ft_fill(m, i - 1, s, result[j]);
			j++;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**result;

	count = count_words(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = 0;
	fill_result(s, c, result);
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
