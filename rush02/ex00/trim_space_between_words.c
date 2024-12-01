/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space_between_words.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:52:04 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 18:17:27 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*wordcpy(char *cur, char *str)
{
	while (*str != '\0' && *str != ' ')
	{
		*cur = *str;
		cur++;
		str++;
	}
	*cur = ' ';
	return (cur);
}

char	*trim_space_between_words(char *str)
{
	char	*result;
	char	*cur;
	char	next_is_word;

	result = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	cur = result;
	next_is_word = 1;
	while (*str)
	{
		if (*str != ' ' && next_is_word)
		{
			cur = wordcpy(cur, str);
			cur++;
			next_is_word = 0;
		}
		else if (*str == ' ')
			next_is_word = 1;
		str++;
	}
	if (*(cur - 1) == ' ')
		cur--;
	*cur = '\0';
	return (result);
}
