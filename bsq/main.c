/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:20:09 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 09:28:32 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	process(int fd)
{
	t_format	format;
	int			**map;
	int			**ans;

	map = read_map(fd, &format);
	if (map == NULL)
	{
		ft_puterror("map error\n");
		return (1);
	}
	ans = solve_map(map, format);
	if (ans == NULL)
	{
		ft_puterror("map error\n");
		free_map(ans, format);
		return (1);
	}
	show_map(map, ans, format);
	free_map(map, format);
	free_map(ans, format);
	return (0);
}

int	process_file(char *fpath)
{
	int	fd;

	fd = open(fpath, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("map error\n");
		return (1);
	}
	return (process(fd));
}

int	main(int argc, char **argv)
{
	int	i;
	int	is_first;

	if (argc == 1)
		process(0);
	else
	{
		i = 1;
		is_first = 1;
		while (i < argc)
		{
			if (!is_first)
				ft_putstr("\n");
			is_first = 0;
			process_file(argv[i]);
			i++;
		}
	}
	return (0);
}
