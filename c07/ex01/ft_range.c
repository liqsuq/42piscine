/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:44:57 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/14 16:39:10 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	*cur;
	int	i;

	if (min >= max)
		return (NULL);
	ptr = malloc((max - min) * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	cur = ptr;
	i = min;
	while (i < max)
	{
		*cur = i;
		cur++;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*num;
	int	i;
	int	min = 51;
	int	max = 100;
	
	num = ft_range(min, max);
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
