/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:14:20 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 09:14:20 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	length;

	s += start;
	length = ft_strlen(s) + 1;
	len++;
	if (length <= len)
	{
		ptr = malloc((length) * sizeof(char));
	}
	else
	{
		ptr = malloc((len) * sizeof(char));
		length = len;
	}
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, length);
	return (ptr);
}
