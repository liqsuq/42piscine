/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:41:05 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/18 20:00:19 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (s1[i] - s2[i]);
}

//*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("ABC ABC: %d\n", ft_strcmp("ABC", "ABC"));
	printf("ABC AB : %d\n", ft_strcmp("ABC", "AB"));
	printf("ABA ABZ: %d\n", ft_strcmp("ABA", "ABZ"));
	printf("ABJ ABC: %d\n", ft_strcmp("ABJ", "ABC"));
	printf("\n");
	printf("ABC ABC: %d\n", strcmp("ABC", "ABC"));
	printf("ABC AB : %d\n", strcmp("ABC", "AB"));
	printf("ABA ABZ: %d\n", strcmp("ABA", "ABZ"));
	printf("ABJ ABC: %d\n", strcmp("ABJ", "ABC"));
	return (0);
}
//*/
