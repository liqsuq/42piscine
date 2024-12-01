/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:38:28 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/20 10:07:58 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*
#include <stdio.h>

int	is_capital(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		return (1);
	else
		return (0);
}

int	main(void)
{
	char *test[] = {"Asd", "asd", "asd", "asd", "Asd"};

	printf("%d\n", ft_count_if(test, 5, &is_capital));
	return (0);
}
//*/
