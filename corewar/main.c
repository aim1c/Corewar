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

void	ft_find_flags(int argc, char **argv)
{
	int		i;
	
	i = 0;
	while (++i < argc)
	{
		
	}
}

void	check_negative_and_magic_header(int fd)
{
	unsigned char buff[4];
	
	if (fd < 1)
		panic_error();
	read(fd, &buff[3], 1);
	read(fd, &buff[2], 1);
	read(fd, &buff[1], 1);
	read(fd, &buff[0], 1);
	if (*(unsigned int *)buff != COREWAR_EXEC_MAGIC)
		panic_error();
}

void	check_fd_with_magic(int argc, char	**argv)
{
	int		i;
	
	i = 0;
	while (++i < argc)
	{
		if (ft_strstr("-n", argv[i]) || ft_strstr("-dump", argv[i]))
			i++;
		else
			check_negative_and_magic_header(open(argv[i], O_RDONLY));
	}
}

void	error_handler(int argc, char **argv)
{
	if (check_unsupport_flags(argc, argv) > 0)
		check_order_numbers(argc, argv);
	check_fd_with_magic(argc, argv);
	ft_printf("Log: - Validation complete\n");
}

int main(int argc, char *argv[])
{
	error_handler(argc, argv);
}
