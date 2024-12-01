/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:03:56 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/11 16:10:29 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*cur_dest;
	char			*cur_src;

	cur_dest = dest;
	cur_src = src;
	while (*cur_dest != '\0')
		cur_dest++;
	i = 0;
	while (*cur_src != '\0' && i < nb)
	{
		*cur_dest = *cur_src;
		cur_dest++;
		cur_src++;
		i++;
	}
	*cur_dest = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char test1[64] = "42\t";
	char test2[64] = "tokyo skytree";
	char test3[64] = "42\t";
	char test4[64] = "tokyo skytree";
	
	printf("test1: %s, test2: %s\n", test1, test2);
	printf("ft_strncat(test1, test2, 24)\n");
	ft_strncat(test1, test2, 24);
	printf("test1: %s, test2: %s\n", test1, test2);
	printf("   strncat(test3, test4, 24)\n");
	strncat(test3, test4, 24);
	printf("test3: %s, test4: %s\n", test3, test4);

	return (0);
}
//*/
