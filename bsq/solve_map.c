/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:12:18 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 07:47:07 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min3(int val1, int val2, int val3)
{
	int	min;

	min = val1;
	if (min > val2)
		min = val2;
	if (min > val3)
		min = val3;
	return (min);
}

void	dynamic_p(int **map, int **val, t_format format)
{
	int	i;
	int	j;

	i = 0;
	while (i < format.line)
	{
		j = 0;
		while (j < format.row)
		{
			if (map[i][j] == 1)
				val[i][j] = 0;
			else if (i == 0 || j == 0)
				val[i][j] = 1;
			else
				val[i][j] = 1
					+ min3(val[i - 1][j - 1], val[i - 1][j], val[i][j - 1]);
			j++;
		}
		i++;
	}
}

t_maximum	calc_max(int **val, t_format format)
{
	int			i;
	int			j;
	t_maximum	max;

	max.size = 0;
	i = 0;
	while (i < format.line)
	{
		j = 0;
		while (j < format.row)
		{
			if (val[i][j] > max.size)
			{
				max.size = val[i][j];
				max.i = i;
				max.j = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	paint_ans(int **ans, t_format format, t_maximum max)
{
	int	i;
	int	j;

	i = 0;
	while (i < format.line)
	{
		j = 0;
		while (j < format.row)
		{
			ans[i][j] = 0;
			j++;
		}
		i++;
	}
	i = max.i;
	while (i > max.i - max.size)
	{
		j = max.j;
		while (j > max.j - max.size)
		{
			ans[i][j] = 1;
			j--;
		}
		i--;
	}
}

int	**solve_map(int **map, t_format format)
{
	int			**val;
	int			**ans;
	t_maximum	max;

	val = alloc_map(format);
	if (val == NULL)
		return (NULL);
	dynamic_p(map, val, format);
	max = calc_max(val, format);
	if (max.size == 0)
		return (NULL);
	ans = alloc_map(format);
	paint_ans(ans, format, max);
	if (ans == NULL)
	{
		free_map(val, format);
		return (NULL);
	}
	free_map(val, format);
	return (ans);
}
