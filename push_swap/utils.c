/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:45:28 by vurrigon          #+#    #+#             */
/*   Updated: 2019/07/07 15:14:49 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_head *head)
{
	t_lst	*b;
	t_lst	*a;
	int		value;

	a = head->a;
	b = head->b;
	value = a->value;
	if (!a || b)
		return (0);
	while (a->next)
	{
		a = a->next;
		if (value > a->value)
			return (0);
		value = a->value;
	}
	return (1);
}

int	get_len_stack(t_lst *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

