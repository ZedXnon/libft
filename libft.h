/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <danielwoidt2@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:12 by dwoidt            #+#    #+#             */
/*   Updated: 2023/12/11 00:31:12 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int argument);
int		ft_isdigit(int argument);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int argument);
size_t	ft_strlen(const char *string);

#endif