//
//  init_caret.c
//  corewar
//
//  Created by Alexander Volkov on 01/11/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"


int			get_position_for_id(int id, int count_of_players)
{
	int		space;
	int		position;
	
	space = MEM_SIZE / count_of_players * id;
	position = space - MEM_SIZE / count_of_players;
	
	return (position);
}

t_caret		*make_head(int id_player, t_vm *vm)
{
	t_caret		*caret;
	int			i;
	
	i = 0;
	caret = (t_caret *)malloc(sizeof(t_caret));
	caret->next = 0;
	caret->id = id_player;
	caret->cicle_to_exec = 0;
	caret->index = get_position_for_id(id_player, vm->count_players);
	caret->reg[0] = id_player * -1;
	caret->carry = 0;
	caret->live_cicle = 0;
	caret->shift = 1;
	while (++i < 16)
		caret->reg[i] = 0;
	return (caret);
}

t_caret		*make_caret_with_count(t_vm *vm, int count_of_players)
{
	t_caret		*head;
	t_caret		*new_node;
	int			i;
	
	i = 0;
	while (++i <= count_of_players)
	{
		if (i == 1)
			head = make_head(i, vm);
		else
		{
			new_node = make_head(i, vm);
			new_node->next = head;
			head = new_node;
		}
	}
	return (head);
}

t_caret		*init_caret(t_vm *vm)
{
	t_caret		*caret;
	
	caret = make_caret_with_count(vm, vm->count_players);
	vm->caret = caret;
	return (caret);
}
