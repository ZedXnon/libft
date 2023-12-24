/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:02:45 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 11:02:45 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void* ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	i;
	size_t total_size = num_elements * element_size;

	i = 0;
	void *memory;
	memory = malloc(total_size);

	while (i < total_size)
	{
		*((unsigned char*)memory + i) = 0;
		i++;
	}
	return (memory);
}