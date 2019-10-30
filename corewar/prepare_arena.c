//
//  prepare_arena.c
//  corewar
//
//  Created by Alexander Volkov on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

static t_champion	*find_for_id(t_champion *ch, int id)
{
	int		i;
	
	i = 0;
	while (++i < 5)
	{
		if (ch->id == id)
			return (ch);
		ch = ch->next;
	}
	return (0);
}

static void	fill_arena(t_vm *vm, t_champion *champion)
{
	int		i;
	int		j;
	int		step;
	
	step = MEM_SIZE / vm->count_players * champion->id;
	i = step - MEM_SIZE / vm->count_players - 1;
	j = -1;
	while (++i < step)
	{
		if (++j < CHAMP_MAX_SIZE)
			vm->map[i] = champion->code[j];
		else
			break ;
	}
}

void	fill_arena_handker(t_vm *vm, t_champion *ch)
{
	int			steps;
	int			id;
	t_champion	*for_id;
	
	id = 0;
	for_id = ch;
	steps = MEM_SIZE / vm->count_players;
	while (42)
	{
		if ((for_id = find_for_id(ch, ++id)) == 0)
			break ;
		fill_arena(vm, for_id);
	}
}
