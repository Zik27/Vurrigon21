/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:24:14 by vurrigon          #+#    #+#             */
/*   Updated: 2019/09/13 16:47:46 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_str_room(char **room, int flag)
{
	int i;

	if (flag)
		i = 0;
	else
		i = 1;
	while (room[i])
		free(room[i++]);
	free(room);
}

void		init_start_end(t_map *map, t_room *room)
{
	if (map->prev_command == START && !map->start)
		map->start = room;
	else if (map->prev_command == EXIT && !map->exit)
		map->exit = room;
	else if ((map->start || map->exit) && (map->prev_command == START ||
		map->prev_command == EXIT))
		error("Invalid start/exit");
}

static void	add_room(char **room, t_room **rooms, t_map *map)
{
	t_room	*new_room;

	if (!(*rooms)->next && (*rooms)->name == NULL)
	{
		(*rooms)->name = room[0];
		(*rooms)->x = ft_atoi(room[1]);
		(*rooms)->y = ft_atoi(room[2]);
		init_start_end(map, (*rooms));
	}
	else
	{
		new_room = init_room(room[0], ft_atoi(room[1]), ft_atoi(room[2]));
		init_start_end(map, new_room);
		new_room->next = (*rooms);
		(*rooms) = new_room;
	}
}

void		parse_rooms(char *str, t_map *map, t_room **rooms)
{
	char	**room;
	int		i;

	i = 1;
	room = ft_strsplit(str, ' ');
	if (room[0][0] == 'L' || ft_strchr(room[0], '-'))
	{
		free_str_room(room, 1);
		error("Invalid room name");
	}
	while (room[i++])
		if (!check_digits(room[i - 1], WITH_NEG) || !check_intmax(room[i - 1]))
		{
			free_str_room(room, 1);
			error("Invalid coordinates");
		}
	if (i != 4)
	{
		free_str_room(room, 1);
		error("Invalid room");
	}
	add_room(room, rooms, map);
	free_str_room(room, 0);
	map->prev_command = 0;
}
