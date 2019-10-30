//
//  check_fd_and_magic_header.c
//  corewar
//
//  Created by Alexander Volkov on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

static	void check_negative_fd_and_header(int fd, int *count_pl)
{
	unsigned char buff[4];
	
	if (fd == -1)
		panic_error();
	*count_pl += 1;
	read(fd, &buff[3], 1);
	read(fd, &buff[2], 1);
	read(fd, &buff[1], 1);
	read(fd, &buff[0], 1);
	if (*(unsigned int *)buff != COREWAR_EXEC_MAGIC)
		panic_error();
	close(fd);
}

void					check_fd_with_magic(int argc, char	**argv, int *count_of_players)
{
	int		i;
	
	i = 0;
	*count_of_players = 0;
	while (++i < argc)
	{
		if (ft_strstr("-n", argv[i]) || ft_strstr("-dump", argv[i]))
			i += 1;
		else
			check_negative_fd_and_header(open(argv[i], O_RDONLY), count_of_players);
	}
	if (*count_of_players < 0 || *count_of_players > 4)
		panic_error();
}
