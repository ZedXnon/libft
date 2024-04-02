/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:10:26 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/24 12:10:26 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	length;

	length = ft_strlen(str) + 1;
	new_str = malloc(length * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, length);
	return (new_str);
}
