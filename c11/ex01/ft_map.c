/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:47 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/20 10:06:01 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc(length * sizeof(int));
	if (ret == NULL)
		return (NULL);
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}

/*
#include <stdio.h>

int	addone(int num)
{
	return (num + 1);
}

	int	main(void)
{
	int	test[] = {123, 456, 789, 0, -1};
	int	*retval;

	retval = ft_map(test, 5, &addone);
	for (int i = 0; i < 5; i++)
		printf("%d\n", retval[i]);
	return (0);
}
//*/
