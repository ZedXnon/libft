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

	new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, ft_strlen(str) + 1);
	return (new_str);
}
