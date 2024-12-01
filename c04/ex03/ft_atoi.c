/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:14:44 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/11 15:01:17 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	char	*cur;
	int		is_negative;
	int		num;

	cur = str;
	is_negative = 0;
	num = 0;
	while (*cur == ' ' || *cur == '\f' || *cur == '\n'
		|| *cur == '\r' || *cur == '\t' || *cur == '\v')
		cur++;
	while (*cur == '+' || *cur == '-')
	{
		if (*cur == '-')
			is_negative = !is_negative;
		cur++;
	}
	while (*cur >= '0' && *cur <= '9')
	{
		num *= 10;
		num += *cur - '0';
		cur++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}

/*
#include <stdio.h>

int main(void)
{
	printf("\" ---+--+1234ab567\": %d\n", ft_atoi(" ---+--+1234ab567"));
	return (0);
}
//*/
