/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:30:14 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 22:19:54 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

void	dump_buffer(t_stats *stats)
{
	static char	old[BUFSIZE];
	static int	dupped = 0;
	int			i;
	int			dup;

	i = 0;
	dup = 1;
	while (stats->counts == 16 && i++ < BUFSIZE)
		if (old[i - 1] != stats->buf[i - 1])
			dup = 0;
	if (!dup || stats->counts != 16)
	{
		display(stats);
		dupped = 0;
	}
	else if (dup && dupped == 0)
	{
		ft_putstr("*\n");
		dupped = 1;
	}
	stats->counts = 0;
	i = 0;
	while (i++ < BUFSIZE)
		old[i - 1] = stats->buf[i - 1];
}

int	hexd_read(int fd, t_stats *s)
{
	ssize_t	rbytes;

	while (1)
	{
		rbytes = read(fd, s->buf + s->counts, BUFSIZE - s->counts);
		if (rbytes < 0)
			return (1);
		if (rbytes == 0)
			break ;
		s->counts += rbytes;
		if (s->counts == 16)
			dump_buffer(s);
		s->rtotal += rbytes;
	}
	return (0);
}

void	hexd(char *binpath, char *fpath, t_stats *stats)
{
	int	fd;

	if (!ft_strcmp(fpath, "stdin"))
		fd = 0;
	else
	{
		fd = open(fpath, O_RDONLY);
		if (fd == -1)
		{
			error_open(binpath, fpath, errno);
			return ;
		}
		stats->is_allng = 0;
	}
	if (hexd_read(fd, stats))
	{
		error_read(binpath, fpath, errno);
		return ;
	}
	if (fd != 0)
		close(fd);
	else if (stats->counts != 0)
		dump_buffer(stats);
}

void	perfile(int argc, char **argv, t_stats *stats)
{
	int	i;

	i = 1;
	if (ft_strcmp(argv[1], "-C") == 0)
	{
		stats->is_cano = 1;
		i++;
	}
	while (i < argc)
	{
		hexd(argv[0], argv[i], stats);
		i++;
	}
	if (stats->counts != 0)
		dump_buffer(stats);
}

int	main(int argc, char **argv)
{
	t_stats	stats;

	init_stats(&stats);
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "-C") == 0))
	{
		stats.is_allng = 0;
		if (argc == 2 && ft_strcmp(argv[1], "-C") == 0)
			stats.is_cano = 1;
		hexd(argv[0], "stdin", &stats);
	}
	else
		perfile(argc, argv, &stats);
	if (stats.is_allng)
		error_all(argv[0]);
	else if (stats.rtotal != 0)
	{
		if (stats.is_cano)
			display_offset(stats.rtotal, 8);
		else
			display_offset(stats.rtotal, 7);
		ft_putstr("\n");
	}
	return (0);
}
