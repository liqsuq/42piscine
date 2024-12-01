/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:57:03 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/19 21:52:24 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int board[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_correct(int *board, int col, int cur)
{
	int	i;

	i = 1;
	while (i <= col)
	{
		if (board[col - i] == cur)
			return (0);
		if (board[col - i] == cur - i || board[col -i] == cur + i)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int col, int *count)
{
	int	i;

	if (col == 10)
	{
		print(board);
		*count += 1;
		return ;
	}
	i = 0;
	while (i <= 9)
	{
		if (is_correct(board, col, i))
		{
			board[col] = i;
			solve(board, col + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

/*
#include <stdio.h>
int	main()
{
	int num;

	num = ft_ten_queens_puzzle();
	printf("%i\n", num);
}
//*/

