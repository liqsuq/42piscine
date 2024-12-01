/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:41:59 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:36:36 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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
	char *test2 = "FourtyTwoTokyo";
	char *test3 = "";

	printf("\"%s\": %d\n", test1, ft_str_is_lowercase(test1));
	printf("\"%s\": %d\n", test2, ft_str_is_lowercase(test2));
	printf("\"%s\": %d\n", test3, ft_str_is_lowercase(test3));
	return (0);
}
//*/
