/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:14:16 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/17 19:14:16 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	uc_s1 = (const unsigned char *)s1;
	uc_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (uc_s1[i] != uc_s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	if (uc_s1[i] < uc_s2[i])
		return (-1);
	else if (uc_s1[i] > uc_s2[i])
		return (1);
	return (0);
}
