/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:00:31 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 22:19:14 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

# define BUFSIZE 16

typedef struct s_stats
{
	int		is_cano;
	int		is_allng;
	ssize_t	counts;
	ssize_t	rtotal;
	char	buf[BUFSIZE];
}	t_stats;

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	putbyte(char str);
void	putascii(char str);
void	init_stats(t_stats *stats);
void	display(t_stats *stats);
void	display_offset(ssize_t rtotal, int digit);
void	display_canonical(char *buf, ssize_t rbytes, ssize_t rtotal);
void	display_default(char *buf, ssize_t rbytes, ssize_t rtotal);
void	error_open(char *binpath, char *fpath, int err);
void	error_read(char *binpath, char *fpath, int err);
void	error_all(char *binpath);

#endif
