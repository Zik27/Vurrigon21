/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:11:12 by djast             #+#    #+#             */
/*   Updated: 2019/09/25 18:49:00 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_champ		*champs;
	t_vm_info	*info;
	t_carriage	*carriages;

	if (argc < 2)
	{
		print_help(argv);
		return (0);
	}
	champs = parse_args(argc, argv);
	info = init_vm_info(champs);
	place_players_on_arena(champs, info);
	carriages = init_carriages(champs, info);

	introducing(champs, info);
	print_carriages(carriages);
	print_map(info->map);
	return (0);
}