/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:47:56 by vurrigon          #+#    #+#             */
/*   Updated: 2019/06/30 14:04:42 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_create_elem(int data)
{
	t_lst	*list;

	if ((list = (t_lst *) malloc(sizeof(t_lst))))
	{
		list->value = data;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}

t_lst	*create_lst(char **data)
{
	t_lst	*head;
	t_lst	*current;
	int		i;

	i = 1;
	if (!(head = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	head->value = ft_atoi(data[i++]);
	head->next = NULL;
	current = head;
	while (data[i])
	{
		current->next = ft_create_elem(ft_atoi(data[i++]));
		current = current->next;
	}
	return (head);
}

t_head	*create_head(char **data)
{
	t_head	*head;

	if ((head = malloc(sizeof(t_head))))
	{
		head->a = create_lst(data);
		head->b = NULL;
		return (head);
	}
	return (NULL);
}