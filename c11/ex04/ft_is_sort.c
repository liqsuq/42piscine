/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:10:30 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/24 22:19:38 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			break ;
		i++;
	}
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	if (i == length - 1)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int ft_diff(int num1, int num2)
{
	return (num1 - num2);
}

int main(void)
{
	int test[] = {5, 3, 3, 3, 6};

	printf("%d\n", ft_is_sort(test, 5, &ft_diff));
	return (0);
}
//*/
