/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:12:23 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 16:55:27 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[8] = "42tokyo";
	char	dest[8] = "!empty!";

	printf("src: %s, dest: %s\n", src, dest);
	ft_strcpy(dest, src);
	printf("src: %s, dest: %s\n", src, dest);
	return (0);
}
//*/
