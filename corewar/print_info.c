//
//  print_info.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

void		print_info(t_champion *ch)
{
	int i;
	int row;
	int colomn;
	
	i = 0;
	row = 0;
	colomn = 0;
	while (ch->id != 1)
		ch = ch->next;
	ft_printf("********** - Player Info -**********\n");
	ft_printf("Player with id: - %d\n", ch->id);
	ft_printf("Has name: - %s\n", ch->name);
	ft_printf("Has comment: - %s\n", ch->comment);
	ft_printf("And his exec code has: - %d bytes\n", ch->size_code);
	ft_printf("This is a code: - \n");
	while(++i < CHAMP_MAX_SIZE)
	{
		if (++row % 64 == 0)
		{
			row = 0;
			ft_printf("\n");
		}
		unsigned char new = ch->code[i];
		ft_printf("%02x", new);
			ft_printf(" ");
	}
	ft_printf("\n*****************************************************************************\n");
}

void	print_arena(t_vm *vm)
{
	int		fd;
	FILE	*fl;
	int		i;
	
	fl = fopen("log/arena", "wt");
	fd = fileno(fl);
	i = -1;
	while (++i < 4096)
	{
		if (i % 64 == 0 && i != 0)
			dprintf(fd, "\n");
		dprintf(fd, "%02x ", vm->map[i]);
	}
}
