/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:50:00 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/15 17:50:00 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_char;
	char		*dest_char;

	if (dest == src || n == 0)
		return (dest);
	dest_char = (char *)dest;
	src_char = (const char *)src;
	while (n--)
	{
		dest_char[n] = src_char[n];
	}
	return (dest);
}
