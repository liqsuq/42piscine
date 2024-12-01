/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:08:48 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/06 10:52:11 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int	main(void)
{
	int	div;
	int	mod;

	ft_div_mod(84, 2, &div, &mod);
	printf("84 / 2 = %d ... %d\n", div, mod);
	ft_div_mod(85, 2, &div, &mod);
	printf("85 / 2 = %d ... %d\n", div, mod);
	ft_div_mod(86, 2, &div, &mod);
	printf("86 / 2 = %d ... %d\n", div, mod);
	return (0);
}
//*/
