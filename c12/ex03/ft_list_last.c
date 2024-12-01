/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:50:02 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 08:53:41 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next != NULL)
		*begin_list = *begin_list->next;
	return (begin_list);
}

//*
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

	test = ft_create_elem("42tokyo");
	i = 0;
	while (i < 42)
	{
		ft_list_push_front(&test, "test");
		i++;
	}
	test = ft_list_last(test);
	printf("last: %s\n", (char *)test->data);
	return (0);
}
//*/
