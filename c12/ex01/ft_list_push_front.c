/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:51:55 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/25 23:32:35 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*ptr;

	ptr = ft_create_elem(data);
	if (ptr == NULL)
		return ;
	ptr->next = *begin_list;
	*begin_list = ptr;
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

	test = ft_create_elem("tokyo\n");
	ft_list_push_front(&test, "42 ");
	print_nodes(test);
	return (0);
}
//*/
