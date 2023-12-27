/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 03:31:58 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/25 03:31:58 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(int *length, int n)
{
	char	*ptr;

	if (n < 0)
	{
		ptr = malloc(sizeof(char) * ((*length) + 2));
		ptr[0] = '-';
		(*length)++;
	}
	else
	{
		ptr = malloc(sizeof(char) * ((*length) + 1));
	}
	return (ptr);
}

static size_t	get_length(int n)
{
	int	length;

	if (n == 0)
		length = 1;
	else
	{
		if (n < 0)
			n = -n;
		length = 0;
		while (n > 0)
		{
			n /= 10;
			length++;
		}
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*ptr;
	size_t	i;

	length = get_length(n);
	ptr = allocate(&length, n);
	if (!ptr)
		return (NULL);
	i = 0;
	ptr[length] = '\0';
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (length > i)
	{
		ptr[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return (ptr);
}
