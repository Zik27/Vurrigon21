/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:02:42 by vurrigon          #+#    #+#             */
/*   Updated: 2019/09/04 11:54:48 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_file_txt(t_file_txt **input, char *line)
{
	t_file_txt	*tmp;

	if (!(*input)->next && !(*input)->text)
		(*input)->text = line;
	else
	{
		tmp = init_input_file(line);
		tmp->next = (*input);
		(*input) = tmp;
	}
}

void	reverse_lst(t_file_txt **lst)
{
	t_file_txt	*current;
	t_file_txt	*before;
	t_file_txt	*after;

	current = *lst;
	after = 0;
	before = NULL;
	while (current)
	{
		after = current->next;
		current->next = before;
		before = current;
		current = after;
	}
	*lst = before;
}
