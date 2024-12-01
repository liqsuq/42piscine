/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:17 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/11 15:06:53 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("-1: %d\n", ft_recursive_factorial(-1));
	printf(" 0: %d\n", ft_recursive_factorial(0));
	printf(" 1: %d\n", ft_recursive_factorial(1));
	printf(" 2: %d\n", ft_recursive_factorial(2));
	printf(" 3: %d\n", ft_recursive_factorial(3));
	printf(" 4: %d\n", ft_recursive_factorial(4));
	printf(" 5: %d\n", ft_recursive_factorial(5));
	printf(" 6: %d\n", ft_recursive_factorial(6));
	printf(" 7: %d\n", ft_recursive_factorial(7));
	printf(" 8: %d\n", ft_recursive_factorial(8));
	printf(" 9: %d\n", ft_recursive_factorial(9));
	printf("10: %d\n", ft_recursive_factorial(10));
	return (0);
}
//*/
