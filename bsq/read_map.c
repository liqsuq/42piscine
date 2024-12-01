/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:16:26 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 12:34:23 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*parse_firstline(char *buf, t_format *f)
{
	if (*buf < '0' || *buf > '9')
		return (NULL);
	f->line = 0;
	while (*buf >= '0' && *buf <= '9')
	{
		f->line *= 10;
		f->line += *buf - '0';
		buf++;
	}
	f->empc = *buf++;
	f->obsc = *buf++;
	f->fulc = *buf++;
	if (f->line < 1 || !is_c(f->empc) || !is_c(f->obsc) || !is_c(f->fulc))
		return (NULL);
	if (f->empc == f->obsc || f->obsc == f->fulc || f->fulc == f->empc)
		return (NULL);
	if (*buf != '\n')
		return (NULL);
	buf++;
	return (buf);
}

void	parse_secondline(char *buf, t_format *f)
{
	f->row = 0;
	while (*buf != '\n' && (*buf == f->empc || *buf == f->obsc))
	{
		f->row++;
		buf++;
	}
}

int	parse(char *buf, int **map, t_format format)
{
	int	i;
	int	j;

	i = 0;
	while (i < format.line)
	{
		map[i] = malloc(format.row * sizeof(int));
		if (map[i] == NULL)
			return (1);
		j = 0;
		while (*buf != '\n' && *buf != '\0')
		{
			map[i][j] = is_obs(*buf++, format);
			if (map[i][j++] < 0)
				return (1);
		}
		if (*buf == '\n')
			buf++;
		if (j != format.row)
			return (1);
		i++;
	}
	return (0);
}

int	**read_map(int fd, t_format *format)
{
	char	buf[BUFSIZE];
	char	*cur;
	ssize_t	rbytes;
	int		**map;

	rbytes = read(fd, buf, BUFSIZE);
	if (rbytes <= 0)
		return (NULL);
	buf[rbytes] = '\0';
	cur = parse_firstline(buf, format);
	if (cur == NULL)
		return (NULL);
	parse_secondline(cur, format);
	if (format->row == 0)
		return (NULL);
	map = malloc(format->line * sizeof(int *));
	if (map == NULL)
		return (NULL);
	if (parse(cur, map, *format))
		return (NULL);
	return (map);
}
