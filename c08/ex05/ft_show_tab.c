/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:18:46 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/19 20:06:28 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(t_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putstr("\n");
		ft_putnbr(par->size);
		ft_putstr("\n");
		ft_putstr(par->copy);
		ft_putstr("\n");
		par++;
	}
}

/*
#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return (cur - str);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*cur_dest;

	cur_dest = dest;
	while (*src != '\0')
	{
		*cur_dest = *src;
		cur_dest++;
		src++;
	}
	*cur_dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	size;
	char			*ptr;

	size = ft_strlen(src);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

void test_copy(char *str)
{
	while (*str)
	{
		*str = 'X';
		str++;
	}
}

int	main(int argc, char **argv)
{
	t_stock_str *stock;

	stock = ft_strs_to_tab(argc, argv);
	test_copy(stock[0].copy);
	ft_show_tab(stock);
	return (0);
}
//*/
