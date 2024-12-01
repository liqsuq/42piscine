/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikeda <mikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:32:32 by mikeda            #+#    #+#             */
/*   Updated: 2024/09/08 17:56:30 by hiryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

//  15552
//  6   6
//  6   6
//  6   6
//  35554

void	line_writer04(int x, int y, int line)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (line == 1 && i == 1)
			ft_putchar('A');
		else if (line == 1 && i == x)
			ft_putchar('C');
		else if (line == y && i == 1)
			ft_putchar('C');
		else if (line == y && i == x)
			ft_putchar('A');
		else if (line == 1 || line == y)
			ft_putchar('B');
		else if (i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush04(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y)
	{
		line_writer04(x, y, line);
		line++;
	}
}
