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
	print_info(ch);
}

int main(int argc, char *argv[])
{
	t_champion	*ch;
	t_vm		*vm;
	
	vm = init_vm();
	ch = init_handler(error_handler(argc, argv), vm);
	parse_handler(ch, argc, argv, vm->count_players);
}


