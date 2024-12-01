/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:43:12 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 09:38:02 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return (cur - str);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	is_c(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}

int	is_obs(char c, t_format format)
{
	if (c == format.obsc)
		return (1);
	else if (c == format.empc)
		return (0);
	else
		return (-1);
}
