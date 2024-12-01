/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiryoshi <hiryoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:37:30 by hiryoshi          #+#    #+#             */
/*   Updated: 2024/09/08 17:56:50 by hiryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line_writer02(int x, int y, int line)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if ((line == 1 && i == 1) || (line == 1 && i == x))
			ft_putchar('A');
		else if ((line == y && i == 1) || (line == y && i == x))
			ft_putchar('C');
		else if (line == 1 || line == y || i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush02(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y)
	{
		line_writer02(x, y, line);
		line++;
	}
}
