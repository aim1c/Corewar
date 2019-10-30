//
//  utils.c
//  corewar
//
//  Created by Alexander Volkov on 29/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "corewar.h"

int		has_prefix(char *str, char sub_char)
{
	int i;
	
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == sub_char)
		return (1);
	return (0);
}

int		all_digits(char *str)
{
	int		i;
	
	i = -1;
	while(str[++i] != 0)
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		find_copy(int *arr, int limits, int default_value)
{
	int		i;
	int		j;
	int		have_copy;
	
	i = -1;
	while (++i < limits)
	{
		have_copy = arr[i];
		j = -1;
		while (++j < limits)
			if (j != i && have_copy == arr[j] && arr[j] != default_value)
				return (0);
	}
	return (1);
}
