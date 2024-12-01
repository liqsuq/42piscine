/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:02:19 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/15 15:44:21 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_line(int line[N], int cond)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	max = 0;
	cnt = 0;
	while (i < N)
	{
		if (line[i] > max)
		{
			max = line[i];
			cnt++;
		}
		i++;
	}
	if (cnt != cond)
		return (1);
	return (0);
}

int	check_col(int cond[N][N], int grid[NXN])
{
	int	i;
	int	j;
	int	line[N];
	int	rev[N];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			line[j] = grid[N * j + i];
			rev[N - 1 - j] = grid[N * j + i];
			j++;
		}
		if (check_line(line, cond[0][i]))
			return (0);
		if (check_line(rev, cond[1][i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int cond[N][N], int grid[NXN])
{
	int	i;
	int	j;
	int	line[N];
	int	rev[N];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			line[j] = grid[N * i + j];
			rev[N - 1 - j] = grid[N * i + j];
			j++;
		}
		if (check_line(line, cond[2][i]))
			return (0);
		if (check_line(rev, cond[3][i]))
			return (0);
		i++;
	}
	return (1);
}

int	check(int cond[N][N], int grid[NXN])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (check_col(cond, grid) && check_row(cond, grid))
			return (1);
		i++;
	}
	return (0);
}
