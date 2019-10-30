//
//  ranking.c
//  corewar
//
//  Created by Frost atronach Snow bear on 30/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

static int		find_id(int *arr)
{
	int		id;
	int		i;
	
	id = 1;
	i = -1;
	while (++i < 4)
	{
		if (id == arr[i])
		{
			id += 1;
			i = -1;
		}
		else if (arr[i] == 0)
			return (id);
	}
	return (id);
}

int		*order_id(int argc, char **argv)
{
	int		*arr;
	int		i;
	int		index;
	int		id;

	i = 0;
	index = -1;
	id = 1;
	arr = (int *)malloc(sizeof(int) * 4);
	ft_bzero(arr, sizeof(int) * 4);
	while (++i < argc)
		if (ft_strstr("-n", argv[i]))
		{
			arr[++index] = ft_atoi(argv[i + 1]);
			i += 2;
		}
		else
			arr[++index] = 5;
	index = -1;
	while (++index < 4)
	{
		if (arr[index] == 5)
			arr[index] = find_id(arr);
	}
	return (arr);
}

void	set_id_and_fd_to_list(int *arr, int argc, char **argv, t_champion *ch)
{
	int		i;
	int		fd;
	int		index;
	
	i = 0;
	index = -1;
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) != -1)
		{
			ch->id = arr[++index];
			ch->own_fd = fd;
			ch = ch->next;
		}
	}
	free(arr);
}
