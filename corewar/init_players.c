//
//  init_players.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

static void		all_to_null(t_champion **ch)
{
	(*ch)->code = 0;
	(*ch)->comment = 0;
	(*ch)->id = 0;
	(*ch)->magic_header = 0;
	(*ch)->name = 0;
	(*ch)->next = 0;
	(*ch)->own_fd = 0;
	(*ch)->size_code = 0;
}

t_champion		*init_handler(int count_of_players, t_vm *vm)
{
	t_champion	*head;
	t_champion	*current;
	int			i;
	
	i = 0;
	if (!(head = (t_champion *)malloc(sizeof(t_champion))))
		panic_memory();
	all_to_null(&head);
	current = head;
	while (++i != count_of_players)
	{
		current->next = (t_champion *)malloc(sizeof(t_champion));
		current = current->next;
		all_to_null(&current);
	}
	current->next = head;
	vm->count_players = count_of_players;
	return (head);
}
