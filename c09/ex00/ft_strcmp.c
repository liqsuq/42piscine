/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:05 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/13 09:46:58 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	while (*s1 && *s2)
	{
		diff = *s1 - *s2;
		if (diff)
			return (diff);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>

int main(void)
{
	printf("ABC ABC: %d\n", ft_strcmp("ABC", "ABC"));
	printf("ABC AB : %d\n", ft_strcmp("ABC", "AB"));
	printf("ABA ABZ: %d\n", ft_strcmp("ABA", "ABZ"));
	printf("ABJ ABC: %d\n", ft_strcmp("ABJ", "ABC"));
	return (0);
}
//*/
