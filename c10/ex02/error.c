/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:12:20 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/21 11:27:34 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <libgen.h>

int	ft_strlen(char *str);

void	error_open(char *binpath, char *fpath, int err)
{
	char	*fstr;
	char	*errstr;

	fstr = basename(fpath);
	errstr = strerror(err);
	write(2, binpath, ft_strlen(binpath));
	write(2, ": cannot open '", 15);
	write(2, fstr, ft_strlen(fstr));
	write(2, "' for reading: ", 15);
	write(2, errstr, ft_strlen(errstr));
	write(2, "\n", 1);
}

void	error_read(char *binpath, char *fpath, int err)
{
	char	*fstr;
	char	*errstr;

	fstr = basename(fpath);
	errstr = strerror(err);
	write(2, binpath, ft_strlen(binpath));
	write(2, ": error reading '", 17);
	write(2, fstr, ft_strlen(fstr));
	write(2, "': ", 3);
	write(2, errstr, ft_strlen(errstr));
	write(2, "\n", 1);
}
