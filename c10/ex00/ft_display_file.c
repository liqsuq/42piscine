/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:21:15 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/22 20:48:28 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	display(int fd)
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
			ft_puterror("Cannot read file.\n");
			return (1);
		}
		wsize = write(1, buf, rsize);
		if (wsize < 0)
		{
			ft_puterror("write() was failed.\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		if (argc == 1)
			ft_puterror("File name missing.\n");
		else
			ft_puterror("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_puterror("Cannot read file.\n");
		return (1);
	}
	if (display(fd))
		return (1);
	close(fd);
	return (0);
}
