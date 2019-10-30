//
//  errors.h
//  corewar
//
//  Created by Alexander Volkov on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#ifndef errors_h
#define errors_h

#include <stdio.h>

void	panic_memory(void);
void	panic_error(void);
void	panic_many_players(void);
void	panic_file_not_find(void);

#endif /* errors_h */
