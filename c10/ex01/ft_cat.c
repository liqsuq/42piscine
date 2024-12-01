/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:05:37 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/21 11:22:31 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>

#define BUFSIZE 1024

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}

void	ft_puterror(char *binpath, char *fpath, int err)
{
	char	*fstr;
	char	*errstr;

	fstr = basename(fpath);
	errstr = strerror(err);
	write(2, binpath, ft_strlen(binpath));
	write(2, ": ", 2);
	write(2, fstr, ft_strlen(fstr));
	write(2, ": ", 2);
	write(2, errstr, ft_strlen(errstr));
	write(2, "\n", 1);
}

int	display(int fd, char *binpath, char *fpath)
{
	char	buf[BUFSIZE];
	ssize_t	rsize;
	ssize_t	wsize;

	rsize = 1;
	while (rsize)
	{
		rsize = read(fd, buf, BUFSIZE);
		if (rsize < 0)
		{
			ft_puterror(binpath, fpath, errno);
			return (1);
		}
		wsize = write(1, buf, rsize);
		if (wsize < 0)
		{
			ft_puterror(binpath, fpath, errno);
			return (1);
		}
	}
	return (0);
}

int	open_file(char *binpath, char *fpath)
{
	int	fd;

	fd = open(fpath, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror(binpath, fpath, errno);
		return (-1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		display(0, argv[0], "stdin");
	else
	{
		i = 1;
		while (i < argc)
		{
			if (*argv[i] == '-')
				display(0, argv[0], "stdin");
			else
			{
				fd = open_file(argv[0], argv[i]);
				if (fd < 0)
					return (1);
				if (display(fd, argv[0], argv[i]))
					return (1);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
