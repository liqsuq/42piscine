/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:44:57 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/06 10:54:31 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}

/*
#include <stdio.h>
   
int	main(void)
{
	printf("%d", ft_strlen("1234"));
	printf("%d", ft_strlen("12"));
	printf("\n");
	return (0);
}
//*/
