//
//  corewar.h
//  corewar
//
//  Created by Frost atronach Snow bear on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#ifndef corewar_h
#define corewar_h

#include "libft.h"
#include <fcntl.h>
#include "errors.h"
#include "oh.h"

typedef struct 			s_vm
{
	int					nbr_cycles;
	int					has_n;
	int					has_dump;
}						t_vm;

typedef struct			s_champion
{
    int					id;
	int					own_fd;
	int					magic_header;
    char				*name;
    char				*comment;
	void				*size_code;
	void				*code;
	struct s_champion	*next;
}						t_champion;

//validate
int		check_unsupport_flags(int argc, char **argv);
void	check_order_numbers(int argc, char **argv);




//util
int		has_prefix(char *str, char sub_char);
int		all_digits(char *str);
#endif /* corewar_h */
