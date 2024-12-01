/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:20:17 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/12 15:41:16 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (size + srclen);
	while (*dest != '\0')
		dest++;
	i = 0;
	while (*src != '\0' && i < (size - destlen - 1))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (destlen + srclen);
}

/*
// cc -Wall -Wextra ft_strlcat.c -lbsd
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	dest1_1[64] = "42";
	char	dest1_2[64] = "42";
	char	dest2_1[64] = "42";
	char	dest2_2[64] = "42";
	char	dest3_1[64] = "42";
	char	dest3_2[64] = "42";
	char	dest4_1[64] = "42";
	char	dest4_2[64] = "42";
	char	dest5_1[64] = "";
	char	dest5_2[64] = "";
	char	dest6_1[64] = "42";
	char	dest6_2[64] = "42";
	char	dest7_1[64] = "";
	char	dest7_2[64] = "";
	char	dest8_1[64] = "42";
	char	dest8_2[64] = "42";
	char	src[64] = "tokyo";
	int		result;

	printf("strlcat(\"42\", \"tokyo\", 8):\n");
	result = strlcat(dest1_1, src, 8);
	printf("%s: %d\n", dest1_1, result);
	result = ft_strlcat(dest1_2, src, 8);
	printf("%s: %d\n", dest1_2, result);
	printf("\n");

	printf("strlcat(\"42\", \"tokyo\", 2):\n");
	result = strlcat(dest2_1, src, 2);
	printf("%s: %d\n", dest2_1, result);
	result = ft_strlcat(dest2_2, src, 2);
	printf("%s: %d\n", dest2_2, result);
	printf("\n");

	printf("strlcat(\"42\", \"tokyo\", 3):\n");
	result = strlcat(dest3_1, src, 3);
	printf("%s: %d\n", dest3_1, result);
	result = ft_strlcat(dest3_2, src, 3);
	printf("%s: %d\n", dest3_2, result);
	printf("\n");

	printf("strlcat(\"42\", \"tokyo\", 8):\n");
	result = strlcat(dest4_1, "", 8);
	printf("%s: %d\n", dest4_1, result);
	result = ft_strlcat(dest4_2, "", 8);
	printf("%s: %d\n", dest4_2, result);
	printf("\n");

	printf("strlcat(\"\", \"tokyo\", 8):\n");
	result = strlcat(dest5_1, src, 8);
	printf("%s: %d\n", dest5_1, result);
	result = ft_strlcat(dest5_2, src, 8);
	printf("%s: %d\n", dest5_2, result);
	printf("\n");

	printf("strlcat(\"42\", \"tokyo\", 0):\n");
	result = strlcat(dest6_1, src, 0);
	printf("%s: %d\n", dest6_1, result);
	result = ft_strlcat(dest6_2, src, 0);
	printf("%s: %d\n", dest6_2, result);
	printf("\n");

	printf("strlcat(\"\", \"tokyo\", 0):\n");
	result = strlcat(dest7_1, src, 0);
	printf("%s: %d\n", dest7_1, result);
	result = ft_strlcat(dest7_2, src, 0);
	printf("%s: %d\n", dest7_2, result);
	printf("\n");

	printf("strlcat(\"42\", \"\", 8):\n");
	result = strlcat(dest8_1, "", 8);
	printf("%s: %d\n", dest8_1, result);
	result = ft_strlcat(dest8_2, "", 8);
	printf("%s: %d\n", dest8_2, result);
	printf("\n");
	return (0);
}
//*/
