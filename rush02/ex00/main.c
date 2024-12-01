/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:23:45 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 18:25:19 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_valid_numstr(char *str)
{
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char				*dict_path;
	t_dict_entry		*dict;
	unsigned long long	num;

	dict_path = "numbers.dict";
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
			dict_path = argv[1];
		if (!is_valid_numstr(argv[argc - 1]))
			return (0);
		num = ft_atoull(argv[argc - 1]);
		if (num > 2000000000000000000)
		{
			ft_putstr("Error\n");
			return (0);
		}
		dict = read_dict(dict_path);
		if (!dict)
			return (0);
		lookup(num, dict);
		ft_putstr("\n");
		free_dict(dict);
	}
	return (0);
}
