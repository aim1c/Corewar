//
//  get_data_from_file.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

char	*get_magic_header(int fd)
{
	char	*header;
	
	if (!(header = (char *)malloc(sizeof(char) * 4)))
		panic_memory();
	ft_bzero(header, 4);
	read(fd, header, 4);
	return (header);
}

unsigned char	*get_name_for_ch(int fd)
{
	unsigned char	*name;
	
	if (!(name = ( unsigned char *)malloc(sizeof(unsigned char) * PROG_NAME_LENGTH)))
		panic_memory();
	ft_bzero(name, PROG_NAME_LENGTH);
	read(fd, name, PROG_NAME_LENGTH);
	return (name);
}

int		get_exec_size(int fd)
{
	unsigned char size[4];
	
	read(fd, &size[3], 1);
	read(fd, &size[2], 1);
	read(fd, &size[1], 1);
	read(fd, &size[0], 1);
	
	if (*(unsigned int *)size > CHAMP_MAX_SIZE)
		panic_error();
	return (*(unsigned int *)size);
}

unsigned char	*get_player_comment(int fd)
{
	unsigned char	*comment;
	
	if (!(comment = (unsigned char *)malloc(sizeof(unsigned char) * COMMENT_LENGTH)))
		panic_memory();
	ft_bzero(comment, COMMENT_LENGTH);
	read(fd, comment, COMMENT_LENGTH);
	return (comment);
}

unsigned char	*get_player_code(int fd)
{
	unsigned char	*code;
	
	if (!(code = (unsigned char *)malloc(sizeof(unsigned char) * CHAMP_MAX_SIZE)))
		panic_memory();
	ft_bzero(code, CHAMP_MAX_SIZE);
	read(fd, code, CHAMP_MAX_SIZE);
	return (code);
}
