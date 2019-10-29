//
//  errors.c
//  corewar
//
//  Created by Alexander Volkov on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "errors.h"
#include "libft.h"

void	panic_error(void)
{
	ft_printf("Wrong format!\n\t./corwar [player 1] [player 2]\n");
	ft_printf("\t-n [integer] - custom players id\n");
	ft_printf("\t-dump [count_to_die] - deadline circle in war\n");
	
	exit(EXIT_FAILURE);
}

void	panic_memory()
{
	ft_printf("Memmory error. I'm terrible sorry.");
	exit(EXIT_FAILURE);
}
