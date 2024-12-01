/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:10:58 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 17:04:36 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*cur;

	cur = str;
	while (*cur != '\0')
	{
		if (*cur >= 'A' && *cur <= 'Z')
		{
			*cur += 32;
		}
		cur++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char test1[64] = "42TOKYO";
	char test2[64] = "FOURTY two TOKYO";

	printf("42TOKYO: %s\n", ft_strlowcase(test1));
	printf("FOURTY two TOKYO: %s\n", ft_strlowcase(test2));
	return (0);
}
//*/
