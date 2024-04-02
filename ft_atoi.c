/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:59:24 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/17 20:59:24 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_sign(const char *str, size_t *i, int *is_negative)
{
	int	has_sign;

	has_sign = 0;
	while (str[*i])
	{
		if ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		{
			if (has_sign)
				break ;
		}
		else if ((str[*i] == '+' || str[*i] == '-') && !has_sign)
		{
			*is_negative = (str[*i] == '-');
			has_sign = 1;
		}
		else
			break ;
		(*i)++;
	}
	return (has_sign);
}

static int	get_num(const char *ptr, int is_negative)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while (ft_isdigit(ptr[i]))
	{
		num = num * 10 + (ptr[i] - '0');
		i++;
	}
	if (is_negative)
		return (-num);
	return (num);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		is_negative;

	i = 0;
	is_negative = 0;
	parse_sign(str, &i, &is_negative);
	if (!ft_isdigit(str[i]))
		return (0);
	return (get_num(str + i, is_negative));
}
