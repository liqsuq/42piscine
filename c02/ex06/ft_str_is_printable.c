/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:41:59 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 21:44:18 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char *test1 = "~!42 Tokyo!~";
	char *test2 = "42\tTokyo";
	char *test3 = "";

	printf("\"%s\": %d\n", test1, ft_str_is_printable(test1));
	printf("\"%s\": %d\n", test2, ft_str_is_printable(test2));
	printf("\"%s\": %d\n", test3, ft_str_is_printable(test3));
	return (0);
}
//*/
