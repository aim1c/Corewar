//
//  unsupport_flags.c
//  corewar
//
//  Created by Alexander Volkov on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

int		check_unsupport_flags(int argc, char **argv)
{
	int		i;
	int		count_flags;
	
	i = 0;
	count_flags = 0;
	while (++i < argc)
	{
		if (has_prefix(argv[i], '-'))
		{
			if (!(ft_strstr("-n", argv[i]) || ft_strstr("-dump", argv[i])))
				panic_error();
			count_flags += 1;
		}
	}
	return (count_flags);
}
