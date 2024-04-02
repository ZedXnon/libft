/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:14:35 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/17 19:14:35 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (i + j < len && haystack[i + j] == needle[j] && j < n_len)
			{
				if (j + 1 == n_len)
				{
					return ((char *)(haystack + i));
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
