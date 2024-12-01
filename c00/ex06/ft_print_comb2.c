/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:40:47 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 19:46:08 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int num)
{
	ft_putchar(num / 10 + '0');
	ft_putchar(num % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;
	int	is_first;

	is_first = 1;
	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			if (!is_first)
				write(1, ", ", 2);
			is_first = 0;
			print_number(num1);
			write(1, " ", 1);
			print_number(num2);
			num2++;
		}
		num1++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
//*/
