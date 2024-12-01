/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:27:49 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 16:20:22 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*cur_dest;
	char	*cur_src;

	cur_dest = dest;
	cur_src = src;
	while (*cur_dest != '\0')
		cur_dest++;
	while (*cur_src != '\0')
	{
		*cur_dest = *cur_src;
		cur_dest++;
		cur_src++;
	}
	*cur_dest = '\0';
	return (dest);
}

/*
#include <stdio.h>

int main(void)
{
	char test1[64] = "42";
	char test2[64] = "tokyo";

	printf("test1: %s, test2: %s\n", test1, test2);
	printf("ft_strcat(test1, test2)\n");
	ft_strcat(test1, test2);
	printf("test1: %s, test2: %s\n", test1, test2);
	return (0);
}
//*/
