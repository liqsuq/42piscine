/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:10:30 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/20 10:07:18 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int is_capital(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		return (1);
	else
		return (0);
}

int main(void)
{
	char *test[] = {"asd", "asd", "asd", "asd", NULL};

	printf("%d\n", ft_any(test, &is_capital));
	return (0);
}
//*/
