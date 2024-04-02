/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:02:22 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 13:02:22 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char const *str, char *dest, size_t *i)
{
	while (*str)
	{
		dest[*i] = *str;
		(*i)++;
		str++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(length * sizeof(char));
	if (!string)
		return (NULL);
	length = 0;
	copy_str(s1, string, &length);
	copy_str(s2, string, &length);
	string[length] = '\0';
	return (string);
}
