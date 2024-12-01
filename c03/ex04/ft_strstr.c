/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:18:48 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/11 14:50:42 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*cur_str;
	char	*search_str;
	char	*search_find;

	cur_str = str;
	if (*to_find == '\0')
		return (str);
	while (*cur_str != '\0')
	{
		search_str = cur_str;
		search_find = to_find;
		while (*search_find != '\0')
		{
			if (*search_str != *search_find)
				break ;
			search_str++;
			search_find++;
		}
		if (*search_find == '\0')
			return (cur_str);
		cur_str++;
	}
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	printf("ft_strstr(\"42tokyo\", \"42\") ... ");
	if(ft_strstr("42tokyo", "42") != NULL)
		printf("Found!!\n");
	else
		printf("Not found.\n");
	printf("ft_strstr(\"42tokyo\", \"tokyo\") ... ");
	if(ft_strstr("42tokyo", "tokyo") != NULL)
		printf("Found!!\n");
	else
		printf("Not found.\n");
	printf("ft_strstr(\"42tokyo\", \"NOTFOUND\") ... ");
	if(ft_strstr("42tokyo", "NOTFOUND") != NULL)
		printf("Found!!\n");
	else
		printf("Not found.\n");
	printf("ft_strstr(\"42tokyo\", \"48akb\") ... ");
	if(ft_strstr("42tokyo", "48akb") != NULL)
		printf("Found!!\n");
	else
		printf("Not found.\n");
	printf("ft_strstr(\"42tokyo\", \"\") ... ");
	if(ft_strstr("42tokyo", "") != NULL)
		printf("Found!!\n");
	else
		printf("Not found.\n");
	return (0);
}
//*/
