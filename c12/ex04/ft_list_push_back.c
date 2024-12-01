/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:41:20 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/26 08:57:23 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list[i].next != NULL)
		i++;
	return (&begin_list[i]);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*ptr;
	t_list	*last;

	ptr = ft_create_elem(data);
	if (ptr == NULL)
		return ;
	last = ft_list_last(*begin_list);
	last->next = ptr;
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

	test = ft_create_elem("42 ");
	ft_list_push_back(&test, "tokyo\n");
	print_nodes(test);
	return (0);
}
//*/
