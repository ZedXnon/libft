/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 01:32:49 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/17 01:32:49 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	const char	*ptr;

	ptr = string;
	while (*string)
		string++;
	while (string >= ptr)
	{
		if (*string == character)
			return ((char *)string);
		string--;
	}
	return (NULL);
}
