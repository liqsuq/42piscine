/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:24:04 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 19:09:52 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*keytoval(unsigned long long key, t_dict_entry *head)
{
	t_dict_entry	*cur;

	cur = head;
	while (cur->next != NULL)
	{
		if (cur->key == key)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

void	set_value(char *val_strt, t_dict_entry *entry)
{
	int	i;

	while (*val_strt == ' ')
		val_strt++;
	i = 0;
	while (val_strt[i] != '\0' && val_strt[i] != '\n')
		i++;
	while (i > 0 && (val_strt[i - 1] == ' ' || val_strt[i - 1] == '\n'))
		i--;
	val_strt[i] = '\0';
	val_strt = trim_space_between_words(val_strt);
	entry->value = malloc(i + 1);
	if (!entry->value)
	{
		free(entry);
		return ;
	}
	i = 0;
	while (val_strt[i])
	{
		entry->value[i] = val_strt[i];
		i++;
	}
	entry->value[i] = '\0';
	free(val_strt);
}

t_dict_entry	*create_entry(char *line)
{
	t_dict_entry		*entry;
	char				*colon_pos;
	char				*value_start;
	unsigned long long	key;

	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
		return (NULL);
	colon_pos = line;
	while (*colon_pos != ':' && *colon_pos != '\0')
		colon_pos++;
	if (*colon_pos == '\0')
	{
		free(entry);
		return (NULL);
	}
	*colon_pos = '\0';
	key = ft_atoull(line);
	entry->key = key;
	value_start = colon_pos + 1;
	set_value(value_start, entry);
	entry->next = NULL;
	return (entry);
}

void	add_entry_to_list(t_dict_entry **head, t_dict_entry *entry)
{
	t_dict_entry	*cur;

	if (*head == NULL)
		*head = entry;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = entry;
	}
}

void	free_dict(t_dict_entry *head)
{
	t_dict_entry	*cur;
	t_dict_entry	*next;

	cur = head;
	while (cur)
	{
		next = cur->next;
		free(cur->value);
		free(cur);
		cur = next;
	}
}
