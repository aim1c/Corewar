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

static t_champion *find_for_id(t_champion *ch, int count_of_players, int id)
{
	int			i;
	
	i = 0;
	while (++i <= count_of_players)
	{
		if (id == ch->id)
			return (ch);
		ch = ch->next;
	}
	return (0);
}

void	introduce_yourself(t_champion *pl, int count_of_players)
{
	int		id;
	
	id = 0;
	ft_printf("Introducing contestants...\n");
	while (++id <= count_of_players)
	{
		pl = find_for_id(pl, count_of_players, id);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", pl->id, pl->size_code, pl->name, pl->comment);
	}
}

void	game(t_vm *vm)
{
	introduce_yourself(vm->players, vm->count_players);
	check_command_test(vm);
}

int		main(int argc, char *argv[])
{
	t_champion	*ch;
	t_vm		*vm;
	
	vm = init_vm();
	ch = init_handler(error_handler(argc, argv), vm);
	parse_handler(ch, argc, argv, vm->count_players);
	fill_arena_handker(vm, ch);
	init_caret(vm);
	give_log(vm);
	game(vm);
	ft_printf("\n");
}

void	give_log(t_vm *vm)
{
	//print_info(vm->players);
	print_caret_info(vm);
	print_arena(vm);
}
