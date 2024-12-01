/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:56:41 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/15 16:30:23 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/* cond
 * +-----------+-----------+-----------+-----------+
 * | col1up    | col2up    | col3up    | co4up     |
 * +-----------+-----------+-----------+-----------+
 * | col1down  | col2down  | col3down  | col4down  |
 * +-----------+-----------+-----------+-----------+
 * | row1left  | row2left  | row3left  | row4left  |
 * +-----------+-----------+-----------+-----------+
 * | row1right | row2right | row3right | row4right |
 * +-----------+-----------+-----------+-----------+
 */

/* grid/ans
 * +------+------+------+------+
 * | [ 0] | [ 1] | [ 2] | [ 3] |
 * +------+------+------+------+
 * | [ 4] | [ 5] | [ 6] | [ 7] |
 * +------+------+------+------+
 * | [ 8] | [ 9] | [10] | [11] |
 * +------+------+------+------+
 * | [12] | [13] | [14] | [15] |
 * +------+------+------+------+
 */

int	check_arg(char *arg)
{
	int	i;
	int	len;

	len = ft_strlen(arg);
	if (len != 2 * NXN - 1)
		return (1);
	i = 0;
	while (i < NXN)
	{
		if ((arg[2 * i] < '1') || (arg[2 * i] > N + '0'))
			return (1);
		if ((i != NXN - 1) && (arg[2 * i + 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}

void	arg_parser(int cond[N][N], char *arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			while (*arg == ' ')
				arg++;
			cond[i][j] = *arg - '0';
			arg++;
			j++;
		}
		i++;
	}
}

void	ans_printer(int ans[NXN])
{
	int	i;

	i = 0;
	while (i < NXN)
	{
		ft_putchar(ans[i] + '0');
		if (i % 4 != N - 1)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	cond[N][N];
	int	*ans;

	if ((argc != 2) || (check_arg(argv[1])))
	{
		ft_putstr("Error\n");
		return (1);
	}
	arg_parser(cond, argv[1]);
	ans = malloc(NXN * sizeof(int));
	if (ans == NULL)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (calc(cond, ans))
	{
		ans_printer(ans);
		return (0);
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
}
