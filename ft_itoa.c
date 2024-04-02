/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:28:40 by dwoidt            #+#    #+#             */
/*   Updated: 2024/04/02 14:28:40 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*allocate(int *length, int n)
{
	char	*ptr;

	if (n < 0)
		ptr = malloc(sizeof(char) * ((*length) + 2));
	else
		ptr = malloc(sizeof(char) * ((*length) + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

static size_t	get_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		length = 1;
		n = 2147483647;
	}
	else if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	fill_string(char *ptr, int n, size_t *i)
{
	int	length;

	length = get_length(n);
	if (n < 0)
	{
		ptr[(*i)++] = '-';
		n = -n;
	}
	ptr[length + *i] = '\0';
	while ((unsigned int)length > 0)
	{
		ptr[(*i) + length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	*i += get_length(n);
}

char	*ft_itoa(int n)
{
	const char	*min_str;
	int			length;
	char		*ptr;
	size_t		i;

	length = get_length(n);
	ptr = allocate(&length, n);
	if (!ptr)
		return (NULL);
	i = 0;
	if (n == -2147483648)
	{
		min_str = "-2147483648";
		while (*min_str)
			ptr[i++] = *min_str++;
		ptr[i] = '\0';
	}
	else
	{
		fill_string(ptr, n, &i);
	}
	return (ptr);
}
