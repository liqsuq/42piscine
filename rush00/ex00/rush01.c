/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:26 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/08 17:54:43 by hiryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

//  15552
//  6   6
//  6   6
//  6   6
//  35554

void	line_writer01(int x, int y, int line)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (line == 1 && i == 1)
			ft_putchar('/');
		else if (line == 1 && i == x)
			ft_putchar('\\');
		else if (line == y && i == 1)
			ft_putchar('\\');
		else if (line == y && i == x)
			ft_putchar('/');
		else if (line == 1 || line == y)
			ft_putchar('*');
		else if (i == 1 || i == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush01(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y)
	{
		line_writer01(x, y, line);
		line++;
	}
}
