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

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*memory;

	if (num_elements == 0 || element_size == 0)
		return (NULL);
	total_size = num_elements * element_size;
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, total_size);
	return (memory);
}
