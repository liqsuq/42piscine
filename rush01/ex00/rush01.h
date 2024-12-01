/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:26:46 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/15 19:26:29 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

# define N 4
# define NXN 16

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		calc(int cond[N][N], int *ans);
int		check(int cond[N][N], int grid[NXN]);
int		ft_strlen(char *str);

#endif
