/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:44:31 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/14 12:18:25 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*cur;

	cur = str;
	while (*cur)
		cur++;
	return ((int)(cur - str));
}

char	*alloc_memory(int size, char **strs, char *sep)
{
	int		size_total;
	int		i;
	char	*ret;

	if (size == 0)
	{
		ret = malloc(sizeof(char));
		*ret = '\0';
		return (ret);
	}
	size_total = 0;
	i = 0;
	while (i < size)
	{
		size_total += ft_strlen(strs[i]);
		i++;
	}
	size_total += (size - 1) * ft_strlen(sep);
	ret = malloc(size_total * sizeof(char));
	return (ret);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*cur_dest;

	cur_dest = dest;
	while (*cur_dest != '\0')
		cur_dest++;
	while (*src != '\0')
	{
		*cur_dest = *src;
		cur_dest++;
		src++;
	}
	*cur_dest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ans;

	ans = alloc_memory(size, strs, sep);
	i = 0;
	while (i < size)
	{
		ft_strcat(ans, strs[i]);
		if (i != size - 1)
			ft_strcat(ans, sep);
		i++;
	}
	return (ans);
}

/*
#include <stdio.h>

int main(void)
{
	char	*buf;
	char	*strs1[] = {"42", "tokyo"};
	char	*strs2[] = {"test1", "test2", "test3", "test4"};
	char	*strs3[] = {"test1", "test2", "test3", "test4"};

	buf = ft_strjoin(2, strs1, " ");
	printf("%s\n", buf);
	buf = ft_strjoin(4, strs2, ", ");
	printf("%s\n", buf);
	buf = ft_strjoin(0, strs3, ", ");
	printf("%s\n", buf);
	return (0);
}
//*/
