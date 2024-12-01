/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:34:03 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/13 10:57:36 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#include <stdio.h>

int main(void)
{
	int x = 4;
	int y = 2;
	char str[64] = "42tokyo";
	char test1[] = "ABC";
	char test2[] = "AB";

	printf("test ft_putchar():\n");
	ft_putchar('a');
	ft_putchar('\n');

	printf("test ft_swap():\n");
	printf("%d, %d\n", x, y);
	ft_swap(&x, &y);
	printf("%d, %d\n", x, y);

	printf("test ft_putstr():\n");
	ft_putstr("42tokyo\n");

	printf("test ft_strlen():\n");
	printf("42tokyo: %d\n", ft_strlen(str));

	printf("test ft_strcmp():\n");
	printf("ft_strcmp(%s, %s) -> %d\n", test1, test2, ft_strcmp(test1, test2));

	return (0);
}
