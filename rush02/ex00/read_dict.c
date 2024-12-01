/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:39:34 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/09/22 11:40:47 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	add_lins_to_lst(char *buff, int bytes_r, int fd, t_dict_entry **head)
{
	char			line[BUFSIZE];
	t_dict_entry	*new_entry;
	int				i;
	int				j;

	while (bytes_r > 0)
	{
		i = 0;
		while (i < bytes_r)
		{
			j = 0;
			while (i < bytes_r && buff[i] != '\n')
				line[j++] = buff[i++];
			line[j] = '\0';
			if (j > 0)
			{
				new_entry = create_entry(line);
				if (new_entry)
					add_entry_to_list(head, new_entry);
			}
		i++;
		}
		bytes_r = read(fd, buff, sizeof(buff));
	}
}

t_dict_entry	*read_dict(char *dict_path)
{
	int				fd;
	char			buffer[BUFSIZE];
	int				bytes_read;
	t_dict_entry	*head;

	head = NULL;
	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	add_lins_to_lst(buffer, bytes_read, fd, &head);
	close(fd);
	return (head);
}
