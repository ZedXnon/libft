/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:35 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 13:32:35 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_chars(int offset, char const *s1, char const *set, size_t i)
{
	size_t	j;
	int		num;
	int		found;

	num = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				num++;
				found = 1;
			}
			j++;
		}
		if (found == 0)
			break ;
		i += offset;
	}
	return (num);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = get_chars(1, s1, set, 0);
	end = get_chars(-1, s1, set, ft_strlen(s1) - 1);
	return (ft_substr(s1, start, ft_strlen(s1) - (start + end)));
}
