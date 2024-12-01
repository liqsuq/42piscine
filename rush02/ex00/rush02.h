/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:24:33 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 18:11:22 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFSIZE 8192
# define SEPSTR " "

typedef struct s_dict_entry
{
	unsigned long long		key;
	char					*value;
	struct s_dict_entry		*next;
}	t_dict_entry;

int					ft_strlen(char *str);
void				ft_putstr(char *str);
unsigned long long	ft_atoull(char *str);
t_dict_entry		*read_dict(char *dict_path);
t_dict_entry		*create_entry(char *line);
void				add_entry_to_list(t_dict_entry **head, t_dict_entry *entry);
void				free_dict(t_dict_entry *head);
int					lookup(unsigned long long num, t_dict_entry *dict);
char				*keytoval(unsigned long long key, t_dict_entry *head);
char				*trim_space_between_words(char *str);

#endif
