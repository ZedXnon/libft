/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:32:14 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 15:32:14 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	check_array(char **array, int j)
{
	if (array[j] == NULL)
	{
		while (j > 0)
		{
			j--;
			free(array[j]);
		}
		free(array);
		return (0);
	}
	return (1);
}

static void	fill_array(char **array, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[j] = malloc((i - start + 1) * sizeof(char));
		if (!check_array(array, j))
			return ;
		ft_strlcpy(array[j], s + start, i - start + 1);
		j++;
	}
}

char	**ft_split(const char *s, char c)
{
	int		substring_count;
	char	**array;

	substring_count = count_substrings(s, c);
	array = malloc((substring_count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	fill_array(array, s, c);
	array[substring_count] = NULL;
	return (array);
}
