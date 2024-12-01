/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:16:42 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/13 10:26:54 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	ret = 1;
	while (power > 0)
	{
		ret *= nb;
		power--;
	}
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("   -1,    2 => 0       : %d\n", ft_iterative_power(   -1,   2));
	printf("    0,    0 => 1       : %d\n", ft_iterative_power(    0,   0));
	printf("    0,    1 => 0       : %d\n", ft_iterative_power(    0,   1));
	printf("    2,    2 => 4       : %d\n", ft_iterative_power(    2,   2));
	printf("    3,    2 => 9       : %d\n", ft_iterative_power(    3,   2));
	printf("    4,    2 => 16      : %d\n", ft_iterative_power(    4,   2));
	printf("    5,    2 => 25      : %d\n", ft_iterative_power(    5,   2));
	printf("    2,    8 => 256     : %d\n", ft_iterative_power(    2,   8));
	printf("    2,   10 => 1024    : %d\n", ft_iterative_power(    2,  10));
	printf("    2,   16 => 65536   : %d\n", ft_iterative_power(    2,  16));
	printf("    2,   24 => 16777216: %d\n", ft_iterative_power(    2,  24));
	printf(" 2999, -274 => 0       : %d\n", ft_iterative_power( 2999,-274));
	printf(" 3780,    0 => 1       : %d\n", ft_iterative_power( 3780,   0));
	printf("-2415,    1 => -2415   : %d\n", ft_iterative_power(-2415,   1));
	printf("    3,    2 => 9       : %d\n", ft_iterative_power(    3,   2));
	printf("    7,    3 => 343     : %d\n", ft_iterative_power(    7,   3));
	printf("    8,    4 => 4096    : %d\n", ft_iterative_power(    8,   4));
	printf("   -8,    5 => -32768  : %d\n", ft_iterative_power(   -8,   5));
	printf("   -6,    6 => 46656   : %d\n", ft_iterative_power(   -6,   6));
	printf("   -3,    8 => 6561    : %d\n", ft_iterative_power(   -3,   8));
	printf("   -1,   10 => 1       : %d\n", ft_iterative_power(   -1,  10));
	return (0);
}
//*/
