/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:55:24 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 19:44:23 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_comb(char ichi, char juu, char hyaku)
{
	if ((ichi != juu) && (juu != hyaku) && (hyaku && ichi))
		if ((hyaku < juu) && (juu < ichi))
			return (1);
	return (0);
}

void	print_numbers(char hyaku, char juu, char ichi)
{
	static int	is_first = 1;

	if (!is_first)
		write(1, ", ", 2);
	write(1, &hyaku, 1);
	write(1, &juu, 1);
	write(1, &ichi, 1);
	if (is_first)
		is_first = 0;
}

void	ft_print_comb(void)
{
	char	hyaku;
	char	juu;
	char	ichi;

	hyaku = '0';
	while (hyaku <= '7')
	{
		juu = hyaku + 1;
		while (juu <= '8')
		{
			ichi = juu + 1;
			while (ichi <= '9')
			{
				print_numbers(hyaku, juu, ichi);
				ichi++;
			}
			juu++;
		}
		hyaku++;
	}
}

/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
//*/
