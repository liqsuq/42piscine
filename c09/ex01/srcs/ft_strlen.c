/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:44:57 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/10 14:42:02 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}

/*
#include <stdio.h>
   
int	main(void)
{
	printf("\"42tokyo\": %d\n", ft_strlen("42tokyo"));
	printf("\"hoge\": %d\n", ft_strlen("hoge"));
	return (0);
}
//*/
