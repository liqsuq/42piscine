/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:08:06 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/19 20:02:56 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return (cur - str);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*cur_dest;

	cur_dest = dest;
	while (*src != '\0')
	{
		*cur_dest = *src;
		cur_dest++;
		src++;
	}
	*cur_dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	size;
	char			*ptr;

	size = ft_strlen(src);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}

//*
#include <stdio.h>

int main(void)
{
	char	str[] = "42tokyo 42tokyo 42tokyo 42tokyo";
	char	*result;

	result = ft_strdup(str);
	printf("%s: %s\n", str, result);
	return (0);
}
//*/
