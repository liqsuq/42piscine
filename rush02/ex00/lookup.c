/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:24:23 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 18:41:25 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned long long	get_largest_key(unsigned long long num, t_dict_entry *dict)
{
	unsigned long long	largest_key;

	largest_key = 0;
	while (dict)
	{
		if (dict->key <= num && dict->key > largest_key)
			largest_key = dict->key;
		dict = dict->next;
	}
	return (largest_key);
}

void	lookup_cent(unsigned long long num, t_dict_entry *dict)
{
	if (num < 20)
		ft_putstr(keytoval(num, dict));
	else
	{
		ft_putstr(keytoval(num / 10 * 10, dict));
		if (num % 10 != 0)
		{
			ft_putstr(SEPSTR);
			ft_putstr(keytoval(num % 10, dict));
		}
	}
}

int	lookup_recursive(unsigned long long num, t_dict_entry *dict)
{
	unsigned long long	largest_key;

	largest_key = get_largest_key(num, dict);
	if (largest_key == 0)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (num < 100)
		lookup_cent(num, dict);
	else
	{
		lookup(num / largest_key, dict);
		ft_putstr(SEPSTR);
		ft_putstr(keytoval(largest_key, dict));
		if (num % largest_key != 0)
		{
			ft_putstr(SEPSTR);
			lookup(num % largest_key, dict);
		}
	}
	return (0);
}

int	lookup(unsigned long long num, t_dict_entry *dict)
{
	if (num == 0)
	{
		ft_putstr(keytoval(0, dict));
		return (0);
	}
	if (lookup_recursive(num, dict))
		return (1);
	return (0);
}
