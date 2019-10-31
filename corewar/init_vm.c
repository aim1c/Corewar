//
//  init_vm.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

t_vm	*init_vm(void)
{
	t_vm *vm;
	
	vm = (t_vm *)malloc(sizeof(t_vm));
	ft_bzero(vm->map, MEM_SIZE);
	vm->cycles_all = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->live_count = 0;
	vm->check_count = 0;
	vm->cycles_after_check = 0;
	vm->players = 0;
	vm->live_pl = 0;
	return (vm);
}
