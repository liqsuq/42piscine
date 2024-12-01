/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:28:14 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 13:49:41 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <libgen.h>

#define BUFSIZE 16384

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	error_open(char *binpath, char *fpath, int err);
void	error_read(char *binpath, char *fpath, int err);

void	print_header(char *fpath)
{
	char		*fstr;
	static int	is_first = 1;

	fstr = basename(fpath);
	if (!is_first)
		write(1, "\n", 1);
	is_first = 0;
	write(1, "==> ", 4);
	write(1, fpath, ft_strlen(fstr));
	write(1, " <==\n", 5);
}

int	display(char *binpath, char *fpath, ssize_t count, int fd)
{
	char	*buf;
	ssize_t	rsize;
	ssize_t	wsize;

	buf = malloc(BUFSIZE * sizeof(char));
	if (buf == NULL)
		return (1);
	rsize = read(fd, buf, BUFSIZE);
	if (rsize < 0)
	{
		error_read(binpath, fpath, errno);
		return (1);
	}
	if ((rsize - count) >= 0)
		wsize = write(1, buf + rsize - count, count);
	else
		wsize = write(1, buf, rsize);
	if (wsize < 0)
		return (1);
	free(buf);
	return (0);
}

int	display_file(char *binpath, char *fpath, ssize_t count, int has_header)
{
	int	fd;

	if (*fpath == '-')
		fd = 0;
	else
	{
		fd = open(fpath, O_RDONLY);
		if (fd == -1)
		{
			error_open(binpath, fpath, errno);
			return (0);
		}
	}
	if (has_header)
	{
		if (*fpath == '-')
			print_header("standard input");
		else
			print_header(fpath);
	}
	if (display(binpath, fpath, count, fd))
		return (1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	count;
	int	i;

	count = 10;
	count = ft_atoi(argv[2]);
	if (count == 0)
		return (0);
	if (argc == 3)
		display(argv[0], "stdin", count, 0);
	else if (argc == 4)
		display_file(argv[0], argv[3], count, 0);
	else
	{
		i = 3;
		while (i < argc)
			if (display_file(argv[0], argv[i++], count, 1))
				return (1);
	}
	return (0);
}
