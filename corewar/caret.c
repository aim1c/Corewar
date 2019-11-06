//
//  caret.c
//  corewar
//
//  Created by Alexander Volkov on 05/11/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "caret.h"
#include "corewar.h"

int		loop_index(int index)
{
	if (index > 4096)
		return (index % MEM_SIZE);
	return (index);
}

void	dead_handler(t_caret *carret, int id)
{
	
}

int		check_command_test(t_vm *vm)
{
	t_caret		*caret;
	
	caret = vm->caret;
	while (++vm->cycles_all)
	{
		if (caret->live_cicle + vm->cycles_to_die < vm->cycles_all)
			dead_handler(vm->caret, caret->id);
		caret->index += 1;
		caret = caret->next;
		if (caret == 0)
			caret = vm->caret;
	}
	return (1);
}
