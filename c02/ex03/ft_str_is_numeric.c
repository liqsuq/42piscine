/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:38:49 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:44:04 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char *test1 = "0123456789";
	char *test2 = "42tokyo";
	char *test3 = "";

	printf("\"%s\": %d\n", test1, ft_str_is_numeric(test1));
	printf("\"%s\": %d\n", test2, ft_str_is_numeric(test2));
	printf("\"%s\": %d\n", test3, ft_str_is_numeric(test3));
	return (0);
}
//*/
