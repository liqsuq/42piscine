/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiryoshi <hiryoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:24:26 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/08 17:56:14 by hiryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line_writer03(int x, int y, int line)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if ((line == 1 && i == 1) || (line == y && i == 1))
			ft_putchar('A');
		else if ((line == 1 && i == x) || (line == y && i == x))
			ft_putchar('C');
		else if (line == 1 || line == y || i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush03(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y)
	{
		line_writer03(x, y, line);
		line++;
	}
}
