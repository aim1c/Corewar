//
//  main.c
//  corewar
//
//  Created by Frost atronach Snow bear on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"
#include "errors.h"
#include "stdio.h"

int		error_handler(int argc, char **argv)
{
	int		count_of_players;
	if (check_unsupport_flags(argc, argv) > 0)
		check_order_numbers(argc, argv);
	check_fd_with_magic(argc, argv, &count_of_players);
	ft_printf("Log: - Validation complete\n");
	return (count_of_players);
}

void	parse_handler(t_champion *ch, int argc, char **argv, int count)
{
	set_id_and_fd_to_list(order_id(argc, argv), argc, argv, ch);
	fill_players(ch, count);
}

t_caret		*make_caret_with_count(int count_of_players)
{
	t_caret		*caret_head;
	t_caret		*caret_cur;
	int			i;
	
	i = 0;
	caret_head = malloc(sizeof(t_caret));
	caret_head->next = 0;
	while (++i <= count_of_players)
	{
		caret_head->id = i;
		caret_head->carry = 0;
		caret_head->reg[0] = i * -1;
	}
	return (caret_head);
}

t_caret		*init_caret(t_vm *vm)
{
	t_caret		*caret;
	
	caret = make_caret_with_count(vm->count_players);
	return (caret);
}

//void	carete_handler(t_vm *vm, t_champion *ch)
//{
//	vm->caret =
//}

int main(int argc, char *argv[])
{
	t_champion	*ch;
	t_vm		*vm;
	
	vm = init_vm();
	ch = init_handler(error_handler(argc, argv), vm);
	parse_handler(ch, argc, argv, vm->count_players);
	fill_arena_handker(vm, ch);
	print_arena(vm);
	ft_printf("\n");
}
