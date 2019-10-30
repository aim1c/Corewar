//
//  parsing_players.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

void	skip_null(int fd)
{
	char buff[4];
	
	read(fd, buff, 4);
}

void	fill_players(t_champion *ch, int count)
{
	int		i;
	
	i = 0;
	while (++i <= count)
	{
		ch->magic_header = get_magic_header(ch->own_fd);
		ch->name = get_name_for_ch(ch->own_fd);
		skip_null(ch->own_fd);
		ch->size_code = get_exec_size(ch->own_fd);
		ch->comment = get_player_comment(ch->own_fd);
		skip_null(ch->own_fd);
		ch->code = get_player_code(ch->own_fd);
		close(ch->own_fd);
		ch = ch->next;
	}
}
