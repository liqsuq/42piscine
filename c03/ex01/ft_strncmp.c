/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:38:04 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/18 20:01:07 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < (n - 1)))
	{
		diff = s1[i] - s2[i];
		if (diff > 0)
			return (1);
		if (diff < 0)
			return (-1);
		i++;
	}
	diff = s1[i] - s2[i];
	if (diff > 0)
		return (1);
	if (diff < 0)
		return (-1);
	return (0);
}

//*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("ft_strncmp(ABC, ABC, 3): %d\n", ft_strncmp("ABC", "ABC", 3));
	printf("ft_strncmp(ABC, AB , 3): %d\n", ft_strncmp("ABC", "AB", 3));
	printf("ft_strncmp(ABC, AB , 2): %d\n", ft_strncmp("ABC", "AB", 2));
	printf("ft_strncmp(ABA, ABZ, 3): %d\n", ft_strncmp("ABA", "ABZ", 3));
	printf("ft_strncmp(ABA, ABZ, 2): %d\n", ft_strncmp("ABA", "ABZ", 2));
	printf("ft_strncmp(ABJ, ABC, 3): %d\n", ft_strncmp("ABJ", "ABC", 3));
	printf("ft_strncmp(ABJ, ABC, 2): %d\n", ft_strncmp("ABJ", "ABC", 2));
	printf("ft_strncmp(ABJ, ABC, 1): %d\n", ft_strncmp("ABJ", "ABC", 1));
	printf("ft_strncmp(ABJ, ABC, 0): %d\n", ft_strncmp("ABJ", "ABC", 0));

	printf("\n");

	printf("strncmp(ABC, ABC, 3): %d\n", strncmp("ABC", "ABC", 3));
	printf("strncmp(ABC, AB , 3): %d\n", strncmp("ABC", "AB", 3));
	printf("strncmp(ABC, AB , 2): %d\n", strncmp("ABC", "AB", 2));
	printf("strncmp(ABA, ABZ, 3): %d\n", strncmp("ABA", "ABZ", 3));
	printf("strncmp(ABA, ABZ, 2): %d\n", strncmp("ABA", "ABZ", 2));
	printf("strncmp(ABJ, ABC, 3): %d\n", strncmp("ABJ", "ABC", 3));
	printf("strncmp(ABJ, ABC, 2): %d\n", strncmp("ABJ", "ABC", 2));
	printf("strncmp(ABJ, ABC, 1): %d\n", strncmp("ABJ", "ABC", 1));
	printf("strncmp(ABJ, ABC, 0): %d\n", strncmp("ABJ", "ABC", 0));
	return (0);
	return (0);
}
//*/
