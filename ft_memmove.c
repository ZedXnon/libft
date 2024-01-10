/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:47:19 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/15 18:47:19 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_char;
	char		*src_buffer;
	char		*dest_char;
	size_t		i;

	if (dest == src || n == 0)
		return (dest);
	src_buffer = (char *)malloc(n);
	if (src_buffer == NULL)
		return (dest);
	dest_char = (char *)dest;
	src_char = (const char *)src;
	i = 0;
	while (i < n)
	{
		src_buffer[i] = src_char[i];
		i++;
	}
	while (n--)
	{
		dest_char[n] = src_buffer[n];
	}
	free(src_buffer);
	return (dest);
}
//TODO: fix memmove to not use malloc.

void *ftt_memmove(void *dest, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d || n == 0)
	{

	}
	

	return (dest);
}