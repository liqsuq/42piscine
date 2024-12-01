/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:24:37 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 22:19:08 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	while (*s1 && *s2)
	{
		diff = *s1++ - *s2++;
		if (diff)
			return (diff);
	}
	return (*s1 - *s2);
}

void	putbyte(char byte)
{
	char	*charset;
	char	left;
	char	right;

	charset = "0123456789abcdef";
	left = charset[byte / 16];
	right = charset[byte % 16];
	write(1, &left, 1);
	write(1, &right, 1);
}

void	putascii(char byte)
{
	if (byte >= ' ' && byte <= '~')
		write(1, &byte, 1);
	else
		write(1, ".", 1);
}

void	init_stats(t_stats *stats)
{
	stats->is_cano = 0;
	stats->is_allng = 1;
	stats->counts = 0;
	stats->rtotal = 0;
}
