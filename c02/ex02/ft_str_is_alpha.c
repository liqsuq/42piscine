/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:12:02 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:43:26 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char *test1 = "fourtytwotokyo";
	char *test2 = "FOURTYTWOTOKYO";
	char *test3 = "42tokyo";
	char *test4 = "";

	printf("\"%s\": %d\n", test1, ft_str_is_alpha(test1));
	printf("\"%s\": %d\n", test2, ft_str_is_alpha(test2));
	printf("\"%s\": %d\n", test3, ft_str_is_alpha(test3));
	printf("\"%s\": %d\n", test4, ft_str_is_alpha(test4));
	return (0);
}
//*/
