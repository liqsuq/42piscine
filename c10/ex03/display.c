/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:00:34 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 22:16:21 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	display_offset(ssize_t rtotal, int digit)
{
	char	*charset;
	char	c;

	charset = "0123456789abcdef";
	if (digit < 1)
		return ;
	display_offset(rtotal / 16, digit - 1);
	c = charset[rtotal % 16];
	write(1, &c, 1);
}

void	display_canonical(char *buf, ssize_t rbytes, ssize_t rtotal)
{
	int		i;

	display_offset(rtotal / 16 * 16, 8);
	i = 0;
	while (i < BUFSIZE)
	{
		if (i == 0 || i == 8)
			ft_putstr(" ");
		ft_putstr(" ");
		if (i++ < rbytes)
			putbyte(buf[i - 1]);
		else
			ft_putstr("  ");
	}
	ft_putstr("  |");
	i = 0;
	while (i < rbytes)
		putascii(buf[i++]);
	ft_putstr("|\n");
}

void	display_default(char *buf, ssize_t rbytes, ssize_t rtotal)
{
	ssize_t	i;

	display_offset(rtotal / 16 * 16, 7);
	i = 0;
	while (i < BUFSIZE)
	{
		ft_putstr(" ");
		if (i < rbytes)
		{
			if (i + 1 < rbytes)
			{
				putbyte(buf[i + 1]);
				putbyte(buf[i]);
			}
			else
			{
				putbyte(0);
				putbyte(buf[i]);
			}
		}
		else
			ft_putstr("    ");
		i += 2;
	}
	ft_putstr("\n");
}

void	display(t_stats *s)
{
	if (s->is_cano)
		display_canonical(s->buf, s->counts, s->rtotal);
	else
		display_default(s->buf, s->counts, s->rtotal);
}
