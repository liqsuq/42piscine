/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:59:40 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 19:44:33 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
#include <stdio.h>

int main(void)
{
	printf(" 1: ");
	fflush(stdout);
	ft_is_negative(1);
	printf("\n");
	printf("-1: ");
	fflush(stdout);
	ft_is_negative(-1);
	printf("\n");
	printf(" 0: ");
	fflush(stdout);
	ft_is_negative(0);
	printf("\n");
	return (0);
}
//*/
