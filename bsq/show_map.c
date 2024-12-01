/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:42:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 07:51:20 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	show_map(int **map, int **ans, t_format format)
{
	int	i;
	int	j;

	i = 0;
	while (i < format.line)
	{
		j = 0;
		while (j < format.row)
		{
			if (ans[i][j])
				write(1, &format.fulc, 1);
			else if (map[i][j])
				write(1, &format.obsc, 1);
			else
				write(1, &format.empc, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
