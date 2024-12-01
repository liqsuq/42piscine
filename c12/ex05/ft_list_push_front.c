/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:51:55 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 09:19:09 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ptr;
	t_list	*list;
	int		i;

	if (size == 0)
		return (NULL);
	ptr = ft_create_elem(strs[0]);
	if (ptr == NULL)
		return (NULL);
	list = ptr;
	i = 1;
	while (i < size)
	{
		ptr = ft_create_elem(strs[i++]);
		if (ptr == NULL)
			return (NULL);
		ptr->next = list;
		list = ptr;
	}
	return (list);
}

/*
#include <unistd.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->next = NULL;
	return (ptr);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_nodes(t_list *node)
{
	ft_putstr(node->data);
	if (node->next != NULL)
		print_nodes(node->next);
}

int	main(void)
{
	t_list	*test;
	char	*strings[] = {"\n", "hoge", "fuga", "piyo"};

	test = ft_list_push_strs(4, strings);
	print_nodes(test);
	return (0);
}
//*/
