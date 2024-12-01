/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:19 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 20:00:02 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int n, int *comb)
{
	static int	is_first = 1;
	int			i;

	if (!is_first)
		write(1, ", ", 2);
	is_first = 0;
	i = 0;
	while (i < n)
		ft_putchar(comb[i++] + '0');
}

void	calc(int n, int i, int num, int *comb)
{
	int	digit;

	if (i == n)
	{
		print_number(n, comb);
		return ;
	}
	digit = num;
	while (digit <= 9)
	{
		comb[i] = digit;
		calc(n, i + 1, digit + 1, comb);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	static int	comb[10];

	if (n > 0 && n < 10)
		calc(n, 0, 0, comb);
}

/*
int main(void)
{
	ft_print_combn(2);
	return (0);
}
//*/
