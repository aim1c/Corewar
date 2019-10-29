//
//  check_order.c
//  corewar
//
//  Created by Alexander Volkov on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

static void	check_n_flag(int argc, char **argv, int index)
{
	if (index + 1 == argc)
		panic_error();
	if (!all_digits(argv[index + 1]))
		panic_error();
	if (index + 2 == argc)
		panic_error();
	if (ft_atoi(argv[index + 1]) < 1 || ft_atoi(argv[index + 1]) > 4)
		panic_error();
}

static void	check_dump_flag(int argc, char **argv, int index)
{
	if (index + 1 == argc)
		panic_error();
	if (!all_digits(argv[index + 1]))
		panic_error();
	if (index + 2 == argc)
		panic_error();
	if (ft_atoi(argv[index + 1]) < 1)
		panic_error();
}

void	check_order_numbers(int argc, char **argv)
{
	int		i;
	
	i = 0;
	while (++i < argc)
	{
		if (ft_strstr("-n", argv[i]))
			check_n_flag(argc, argv, i);
		if (ft_strstr("-dump", argv[i]))
			check_dump_flag(argc, argv, i);
	}
}
