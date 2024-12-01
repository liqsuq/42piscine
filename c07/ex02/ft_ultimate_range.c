/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:20:49 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/14 16:48:14 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	ptr = malloc((max - min) * sizeof(int));
	*range = ptr;
	if (ptr == NULL)
		return (-1);
	i = min;
	while (i < max)
	{
		*ptr = i;
		ptr++;
		i++;
	}
	return (max - min);
}

/*
#include <stdio.h>

int main(void)
{
	int	*num;
	int	i;
	int	size;
	int	min = 51;
	int	max = 51;

	size = ft_ultimate_range(&num, min, max);
	printf("size:%d\n", size);
	if (num != NULL)
	{
		i = 0;
		while (i < max - min)
			printf("%d, ", *(num + i++));
		printf("\n");
	}
	else
	{
		printf("NULL\n");
	}
	return (0);
}
//*/
