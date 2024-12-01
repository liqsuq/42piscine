/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:20:40 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/06 10:51:18 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
#include <stdio.h>

int	main(void)
{
	int	test1;
	int	test2;

	test1 = 4;
	test2 = 2;
	printf("%d, %d\n", test1, test2);
	ft_swap(&test1, &test2);
	printf("%d, %d\n", test1, test2);
	return (0);
}
//*/
