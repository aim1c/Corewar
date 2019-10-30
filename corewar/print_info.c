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
	ft_printf("***************************** - Corewar Info - ******************************\n");
	ft_printf("Player with id: - %d\n", ch->id);
	ft_printf("Has name: - %s\n", ch->name);
	ft_printf("Has comment: - %s\n", ch->comment);
	ft_printf("And his exec code has: - %d bytes\n", ch->size_code);
	ft_printf("This is a code: - \n");
	while(++i < CHAMP_MAX_SIZE)
	{
		unsigned char new = ch->code[i];
		ft_printf("%02x", new);
			ft_printf(" ");
		if (++row == 30)
		{
			row = 0;
			ft_printf("\n");
		}
	}
	ft_printf("*****************************************************************************\n");
}
