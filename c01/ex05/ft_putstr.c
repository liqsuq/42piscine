/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:33:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/06 10:53:31 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <unistd.h>

int	main(void)
{
	ft_putstr("42Tokyo");
	ft_putstr("\n");
	ft_putstr("Piscine");
	return (0);
}
/*/
