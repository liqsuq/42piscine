/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:42:29 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 17:03:55 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*cur;

	cur = str;
	while (*cur != '\0')
	{
		if (*cur >= 'a' && *cur <= 'z')
		{
			*cur -= 32;
		}
		cur++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char test1[64] = "42tokyo";
	char test2[64] = "fourty two tokyo";

	printf("42tokyo: %s\n", ft_strupcase(test1));
	printf("fourty TWO tokyo: %s\n", ft_strupcase(test2));
	return (0);
}
//*/
