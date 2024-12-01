/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:24:37 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 19:21:41 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}


void	error_open(char *binpath, char *fpath, int err)
{
	char	*binstr;
	char	*errstr;

	binstr = basename(binpath);
	errstr = strerror(err);
	ft_putstr(binstr);
	ft_putstr(": ");
	ft_putstr(fpath);
	ft_putstr(": ");
	ft_putstr(errstr);
	ft_putstr("\n");
}

void	error_read(char *binpath, char *fpath, int err)
{
	char	*binstr;
	char	*errstr;

	binstr = basename(binpath);
	errstr = strerror(err);
	ft_putstr(binstr);
	ft_putstr(": ");
	ft_putstr(fpath);
	ft_putstr(": ");
	ft_putstr(errstr);
	ft_putstr("\n");
}

void	error_all(char *binpath)
{
	char	*binstr;

	binstr = basename(binpath);
	ft_putstr(binstr);
	ft_putstr(": all input file arguments failed\n");
}
