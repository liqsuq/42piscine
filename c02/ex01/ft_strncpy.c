/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:42:39 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:42:25 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < (int)n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int)n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[8] = "42tokyo";
	char	dest1[8];
	char	dest2[8];

	ft_strncpy(dest1, src, 8);
	printf("ft_strncpy(dest, \"42tokyo\", 8), dest: %s\n", dest1);
	ft_strncpy(dest2, src, 2);
	printf("ft_strncpy(dest, \"42tokyo\", 2), dest: %s\n", dest2);
	return (0);
}
//*/
