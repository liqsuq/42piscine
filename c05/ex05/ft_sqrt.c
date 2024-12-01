/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:45 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/13 11:54:31 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int					left;
	int					right;
	unsigned long long	mid;

	if (nb < 0)
		return (0);
	left = 0;
	right = nb;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid > (unsigned long long)nb)
			right = mid - 1;
		else if (mid * mid < (unsigned long long)nb)
			left = mid + 1;
		else
			return (mid);
	}
	return (0);
}

/*

int main(void)
{
	printf(" -1: %d\n", ft_sqrt( -1));
	printf("  0: %d\n", ft_sqrt(  0));
	printf("  1: %d\n", ft_sqrt(  1));
	printf("  2: %d\n", ft_sqrt(  2));
	printf("  4: %d\n", ft_sqrt(  4));
	printf("  9: %d\n", ft_sqrt(  9));
	printf(" 16: %d\n", ft_sqrt( 16));
	printf(" 25: %d\n", ft_sqrt( 25));
	printf(" 36: %d\n", ft_sqrt( 36));
	printf(" 49: %d\n", ft_sqrt( 49));
	printf(" 64: %d\n", ft_sqrt( 64));
	printf(" 81: %d\n", ft_sqrt( 81));
	printf("100: %d\n", ft_sqrt(100));
	printf("121: %d\n", ft_sqrt(121));
	printf("144: %d\n", ft_sqrt(144));
	printf("169: %d\n", ft_sqrt(169));
	printf("196: %d\n", ft_sqrt(196));
	printf("225: %d\n", ft_sqrt(225));
	printf("256: %d\n", ft_sqrt(256));
	printf("289: %d\n", ft_sqrt(289));
	printf("324: %d\n", ft_sqrt(324));
	printf("361: %d\n", ft_sqrt(361));
	printf("400: %d\n", ft_sqrt(400));
	return 0;
}
//*/
