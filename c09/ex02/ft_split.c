/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:31:22 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/19 16:57:50 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (*charset == str)
			return (1);
		charset++;
	}
	return (0);
}

int	count_split(char *str, char *charset)
{
	int	count;
	int	next_is_split;

	count = 0;
	next_is_split = 0;
	while (*str)
	{
		if (!(is_charset(*str, charset) && next_is_split))
		{
			count++;
			next_is_split = 0;
		}
		else if (is_charset(*str, charset))
			next_is_split = 1;
		str++;
	}
	return (count);
}

unsigned int	splitlen(char *str, char *charset)
{
	char	*cur;

	cur = str;
	while (*cur && !is_charset(*cur, charset))
		cur++;
	return (cur - str);
}

char	*splitdup(char *str, char *charset)
{
	char			*split;
	char			*cur;

	split = malloc((splitlen(str, charset) + 1) * sizeof(char));
	if (split == NULL)
		return (NULL);
	cur = split;
	while (*str && !is_charset(*str, charset))
	{
		*cur = *str;
		cur++;
		str++;
	}
	*cur = '\0';
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	char	**cur;
	int		next_is_split;

	splits = malloc((count_split(str, charset) + 1) * sizeof(char *));
	if (splits == NULL)
		return (NULL);
	cur = splits;
	next_is_split = 1;
	while (*str)
	{
		if (!is_charset(*str, charset) && next_is_split)
		{
			*cur = splitdup(str, charset);
			cur++;
			next_is_split = 0;
		}
		else if (is_charset(*str, charset))
			next_is_split = 1;
		str++;
	}
	*cur = NULL;
	return (splits);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "/test1/,te-st2,///test3///,";
	char	charset[] = ",/-";
	char	**splits;

	splits = ft_split(str, charset);
	while (*splits != NULL)
	{
		printf("%s\n", *splits);
		splits++;
	}
	return (0);
}
//*/
