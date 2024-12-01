/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:33:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/13 10:18:34 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/*
int	main(void)
{
	ft_putstr("42Tokyo");
	ft_putstr("\n");
	ft_putstr("Piscine");
	ft_putstr("\n");
	return (0);
}
//*/
