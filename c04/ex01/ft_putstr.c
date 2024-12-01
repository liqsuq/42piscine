/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:33:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/10 14:43:53 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
	{
		write(1, cur, 1);
		cur++;
	}
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
