/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:46:53 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/12 17:56:57 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	ret = 1;
	while (nb > 0)
		ret *= nb--;
	return (ret);
}

/*/
#include <stdio.h>

int	main(void)
{
	printf("-1: %d\n", ft_iterative_factorial(-1));
	printf(" 0: %d\n", ft_iterative_factorial(0));
	printf(" 1: %d\n", ft_iterative_factorial(1));
	printf(" 2: %d\n", ft_iterative_factorial(2));
	printf(" 3: %d\n", ft_iterative_factorial(3));
	printf(" 4: %d\n", ft_iterative_factorial(4));
	printf(" 5: %d\n", ft_iterative_factorial(5));
	printf(" 6: %d\n", ft_iterative_factorial(6));
	printf(" 7: %d\n", ft_iterative_factorial(7));
	printf(" 8: %d\n", ft_iterative_factorial(8));
	printf(" 9: %d\n", ft_iterative_factorial(9));
	printf("10: %d\n", ft_iterative_factorial(10));
	return (0);
}
//*/
