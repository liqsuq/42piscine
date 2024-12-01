/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:43:15 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 07:31:20 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**alloc_map(t_format format)
{
	int	i;
	int	**ptr;

	ptr = malloc(format.line * sizeof(int *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < format.line)
	{
		ptr[i] = malloc(format.row * sizeof(int));
		i++;
	}
	return (ptr);
}

void	free_map(int **ptr, t_format format)
{
	int	i;

	if (ptr != NULL)
	{
		i = 0;
		while (i < format.line)
			free(ptr[i++]);
		free(ptr);
		ptr = NULL;
	}
}
