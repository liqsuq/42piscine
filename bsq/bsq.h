/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:47:26 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 21:20:58 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFSIZE 65536

typedef struct s_format
{
	int		line;
	int		row;
	char	empc;
	char	obsc;
	char	fulc;
}	t_format;

typedef struct s_maximum
{
	int	size;
	int	i;
	int	j;
}	t_maximum;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
int		is_c(char c);
int		is_obs(char c, t_format format);
int		**read_map(int fd, t_format *format);
int		**solve_map(int **map, t_format format);
void	show_map(int **map, int **ans, t_format format);
int		**alloc_map(t_format format);
void	free_map(int **map, t_format format);

#endif
