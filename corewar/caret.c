//
//  caret.c
//  corewar
//
//  Created by Alexander Volkov on 05/11/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "caret.h"
#include "corewar.h"

void	state_before_new_caret(t_caret *vm)
{
	t_caret *cur = vm;
	
	while (cur)
	{
		ft_printf("id: %d\n", cur->id);
		cur = cur->next;
	}
	//sleep(4);
}

int		loop_index(int index)
{
	if (index > 4096)
		return (index % MEM_SIZE);
	return (index);
}

int		all_null(t_caret *need_kill)
{
	int			i;
	
	i = -1;
	need_kill->carry = 0;
	need_kill->cicle_to_exec = 0;
	need_kill->code = 0;
	need_kill->id = 0;
	need_kill->index = 0;
	need_kill->live_cicle = 0;
	need_kill->next = 0;
	need_kill->shift = 0;
	while (++i < 16)
		need_kill->reg[i] = 0;
	free(need_kill);
	return (1);
}

int		kill_head(t_caret **head)
{
	t_caret		*need_kill;

	need_kill = *head;
	(*head) = (*head)->next;
	all_null(need_kill);
	return (1);
}

int		kill_tail(t_caret **head, t_caret *tail)
{
	t_caret		*cur;
	
	cur = *head;
	while (cur)
	{
		if (cur->next == tail)
		{
			all_null(tail);
			cur->next = 0;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void	just_kill(t_caret **head, t_caret *victim)
{
	t_caret		*cur;
	t_caret		*prev;
	t_caret		*after_victim;
	
	cur = *head;
	while (cur)
	{
		if (cur->next == victim)
		{
			prev = cur;
			after_victim = cur->next->next;
			all_null(victim);
			prev->next = after_victim;
		}
		cur = cur->next;
	}
}

void	dead_handler(t_caret *carre, t_vm *vm)
{
	ft_printf("String LOG: - Need to kill carete with id: ");
	if (vm->caret == carre) {
		ft_printf("%d - It's head\n", carre->id);
		kill_head(&vm->caret);
	}
	else if (carre->next == 0) {
		ft_printf("%d - It's head\n", carre->id);
		kill_tail(&vm->caret, carre);
	}
	else {
		ft_printf("%d - It's just\n", carre->id);
		just_kill(&vm->caret, carre);
	}
	state_before_new_caret(vm->caret);
}

void	fork_caret(t_caret **list, t_caret *copy)
{
	t_caret		*new;
	int			register_index;
	int			id;
	
	register_index = -1;
	new = malloc(sizeof(t_caret));
	id = (*list)->id;
	new->carry = copy->carry;
	new->live_cicle = copy->live_cicle;
	while (++register_index < 16)
		new->reg[register_index] = copy->reg[register_index];
	new->id = id + 1;
	new->cicle_to_exec = 0;
	new->index = copy->index + 20;
	new->next = *list;
	*list = new;
}

int		operating(t_vm *vm)
{
	t_caret		*caret;
	
	caret = vm->caret;
	
	return (1);
}
