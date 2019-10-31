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
	uint8_t				map[MEM_SIZE];
	int					count_players;
	ssize_t				cycles_all;
	ssize_t				cycles_to_die;
	ssize_t				live_count;
	ssize_t				check_count;
	ssize_t				cycles_after_check;
	struct s_champion	*players;
	struct s_champion   *live_pl;
	struct s_caret		*caret;
}						t_vm;

typedef struct			s_champion
{
    int					id;
	int					own_fd;
	char				*magic_header;
    unsigned char		*name;
    unsigned char		*comment;
	int					size_code;
	unsigned char		*code;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_caret
{
	int					id;
	int					carry;
	uint8_t				code;
	ssize_t				live_cicle;
	int					cicle_to_exec;
	ssize_t				shift;
	int					index;
	int32_t				reg[REG_NUMBER];
	struct s_caret		*next;
}						t_caret;

//validate
int						check_unsupport_flags(int argc, char **argv);
void					check_order_numbers(int argc, char **argv);
void					check_fd_with_magic(int argc, char	**argv, int *count_of_players);

//inits
t_champion				*init_handler(int count_of_players, t_vm *vm);
t_vm					*init_vm(void);

//parsing
int						*order_id(int argc, char **argv);
void					set_id_and_fd_to_list(int *arr, int argc, char **argv, t_champion *ch);

// parsing 1.1 to player struct
char					*get_magic_header(int fd);
unsigned char			*get_name_for_ch(int fd);
int						get_exec_size(int fd);
unsigned char			*get_player_comment(int fd);
unsigned char			*get_player_code(int fd);
void					fill_players(t_champion *ch, int count);

//print info
void					print_info(t_champion *ch);
void					print_arena(t_vm *vm);

//arena fill
void					fill_arena_handker(t_vm *vm, t_champion *ch);


//util
int						has_prefix(char *str, char sub_char);
int						all_digits(char *str);
int						find_copy(int *arr, int limits, int default_value);

#endif /* corewar_h */
