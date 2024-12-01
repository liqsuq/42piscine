/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:41:59 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:38:28 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char *test1 = "FOURTYTWOTOKYO";
	char *test2 = "fourtyTWOtokyo";
	char *test3 = "";

	printf("\"%s\": %d\n", test1, ft_str_is_uppercase(test1));
	printf("\"%s\": %d\n", test2, ft_str_is_uppercase(test2));
	printf("\"%s\": %d\n", test3, ft_str_is_uppercase(test3));
	return (0);
}
//*/
