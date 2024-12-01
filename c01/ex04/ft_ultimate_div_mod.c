/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:52:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/06 10:52:57 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 84;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("84 / 2 = %d ... %d\n", a, b);
	a = 85;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("84 / 2 = %d ... %d\n", a, b);
	a = 86;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("84 / 2 = %d ... %d\n", a, b);
	return (0);
}
//*/
