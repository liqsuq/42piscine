/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:07:24 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 08:47:15 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list->next != NULL)
	{
		*begin_list = *begin_list->next;
		i++;
	}
	return (i);
}

/*
#include <unistd.h>
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*ptr;

	ptr = ft_create_elem(data);
	if (ptr == NULL)
		return ;
	ptr->next = *begin_list;
	*begin_list = ptr;
}

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
	int	i;

	test = ft_create_elem("test");
	i = 0;
	while (i < 42)
	{
		ft_list_push_front(&test, "test");
		i++;
	}
	printf("size: %d\n", ft_list_size(test));
	return (0);
}
//*/
