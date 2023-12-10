/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <danielwoidt2@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:28:39 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/11 00:28:39 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isalpha(int argument)
{
	if ((argument >= 'a' && argument <= 'z')
		|| (argument >= 'A' && argument <= 'Z'))
		return (1);
	else
		return (0);
}
