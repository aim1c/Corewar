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


# define MAX_PLAYERS 4
# define MEM_SIZE (4 * 1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

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


#endif /* corewar_h */
