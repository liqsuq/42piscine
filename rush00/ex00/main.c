/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiryoshi <hiryoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:01:24 by hiryoshi          #+#    #+#             */
/*   Updated: 2024/09/08 19:36:32 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	usr_atoi(char *str)
{
	char	*cur;
	char	is_negative;
	int		num;

	cur = str;
	is_negative = 0;
	num = 0;
	while (*cur == ' ')
		cur++;
	if (*cur == '-')
	{
		is_negative = 1;
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

int	select_pattern(int x, int y, char *pattern)
{
	if (*pattern == '0')
		rush00(x, y);
	else if (*pattern == '1')
		rush01(x, y);
	else if (*pattern == '2')
		rush02(x, y);
	else if (*pattern == '3')
		rush03(x, y);
	else if (*pattern == '4')
		rush04(x, y);
	else
	{
		write(2, "invalid arguments!\n", 19);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc < 3)
	{
		write(2, "too few arguments!\n", 19);
		return (1);
	}
	x = usr_atoi(argv[1]);
	y = usr_atoi(argv[2]);
	if (x <= 0 || y <= 0)
	{
		write(2, "invalid arguments!\n", 19);
		return (1);
	}
	if (argc == 3)
		rush03(x, y);
	else if (argc == 4)
		return (select_pattern(x, y, argv[3]));
	else
	{
		write(2, "too many arguments!\n", 20);
		return (1);
	}
}
