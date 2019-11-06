//
//  commands.h
//  corewar
//
//  Created by Frost atronach Snow bear on 06/11/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#ifndef commands_h
#define commands_h

#include "corewar.h"


typedef struct	s_asm
{
	char		*name;
	u_int16_t	code;
	u_int16_t	is_change_carry;
	int			code_types;
	int			number_of_args;
	u_int16_t	args_type[3];
	u_int16_t	size_tdir;
	u_int16_t	cycle_to_exec;
}				t_asm;

static t_asm	arr_com[16] = {
	{
		.name = "live",
		.code = 0X01,
		.is_change_carry = 0,
		.code_types = 0,
		.number_of_args = 1,
		.args_type = {T_DIR, 0, 0},
		.size_tdir = 4,
		.cycle_to_exec = 10
	},
	{
		.name = "ld",
		.code = 0X02,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 2,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.size_tdir = 4,
		.cycle_to_exec = 5
	},
	{
		.name = "st",
		.code = 0X03,
		.is_change_carry = 0,
		.code_types = 1,
		.number_of_args = 2,
		.args_type = {T_REG, T_REG | T_IND, 0},
		.size_tdir = 4,
		.cycle_to_exec = 5
	},
	{
		.name = "add",
		.code = 0X04,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG, T_REG, T_REG},
		.size_tdir = 4,
		.cycle_to_exec = 10
	},
	{
		.name = "sub",
		.code = 0X05,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG, T_REG, T_REG},
		.size_tdir = 4,
		.cycle_to_exec = 10
	},
	{
		.name = "and",
		.code = 0X06,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.size_tdir = 4,
		.cycle_to_exec = 6
	},
	{
		.name = "or",
		.code = 0X07,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.size_tdir = 4,
		.cycle_to_exec = 6
	},
	{
		.name = "xor",
		.code = 0X08,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.size_tdir = 4,
		.cycle_to_exec = 6
	},
	{
		.name = "zjmp",
		.code = 0X09,
		.is_change_carry = 0,
		.code_types = 0,
		.number_of_args = 1,
		.args_type = {T_DIR, 0, 0},
		.size_tdir = 2,
		.cycle_to_exec = 20
	},
	{
		.name = "ldi",
		.code = 0X0a,
		.is_change_carry = 0,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_DIR | T_REG | T_IND, T_REG | T_DIR, T_REG},
		.size_tdir = 2,
		.cycle_to_exec = 25
	},
	{
		.name = "sti",
		.code = 0X0b,
		.is_change_carry = 0,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG, T_DIR | T_REG | T_IND, T_REG | T_DIR},
		.size_tdir = 2,
		.cycle_to_exec = 25
	},
	{
		.name = "fork",
		.code = 0X0c,
		.is_change_carry = 0,
		.code_types = 0,
		.number_of_args = 1,
		.args_type = {T_DIR, 0, 0},
		.size_tdir = 2,
		.cycle_to_exec = 800
	},
	{
		.name = "lld",
		.code = 0X0d,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 2,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.size_tdir = 4,
		.cycle_to_exec = 10
	},
	{
		.name = "lldi",
		.code = 0X0e,
		.is_change_carry = 1,
		.code_types = 1,
		.number_of_args = 3,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.size_tdir = 2,
		.cycle_to_exec = 50
	},
	{
		.name = "lfork",
		.code = 0X0f,
		.is_change_carry = 0,
		.code_types = 0,
		.number_of_args = 1,
		.args_type = {T_DIR, 0, 0},
		.size_tdir = 2,
		.cycle_to_exec = 1000
	},
	{
		.name = "aff",
		.code = 0X10,
		.is_change_carry = 0,
		.code_types = 1,
		.number_of_args = 1,
		.args_type = {T_REG, 0, 0},
		.size_tdir = 4,
		.cycle_to_exec = 2
	}
};

#endif /* commands_h */
