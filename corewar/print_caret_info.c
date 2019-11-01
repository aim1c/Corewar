//
//  print_caret_info.c
//  corewar
//
//  Created by Alexander Volkov on 01/11/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"
#include <inttypes.h>
void					print_caret_info(t_vm *vm)
{
	t_caret		*caret;
	FILE		*ft;
	int			fd;
	int			count_caret;
	int			i;
	
	caret = vm->caret;
	count_caret = caret->id + 1;
	ft = fopen("log/carete", "wt");
	fd = fileno(ft);
	dprintf(fd, "********** Hello! This is carete LOG **********\n");
	dprintf(fd, "********** In this file you can see  **********\n");
	dprintf(fd, "********** the state after initiate  **********\n");
	dprintf(fd, "********** Carete/Cursor/Каретка     **********\n\n");
	while (--count_caret > 0)
	{
		i = -1;
		dprintf(fd, "ID:\t\t%d\n", caret->id);
		dprintf(fd, "CARRY:\t\t%d\n", caret->carry);
		dprintf(fd, "INDEX:\t\t%d\n", caret->index);
		dprintf(fd, "REGISTERS: \t|");
		while (++i < 16)
			dprintf(fd, "%" PRId32 "|", caret->reg[i]);
		dprintf(fd, "\n\t\t---------------- Let's start to next carete! ----------------\t\t\n");
		caret = caret->next;
	}
}
