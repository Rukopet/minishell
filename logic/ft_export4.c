#include "header.h"

void	free_already_exist_key(t_mylst *add, t_mylst *current, char *cur)
{
	if (cur)
		free(cur);
	if (!add->plus)
		current->value = add->value;
	free(add->key);
	free(add);
}

// add list to back

t_mylst	*my_lst_add_back(t_bin *bin, t_mylst *start, t_mylst *add)
{
	t_mylst	*last;

	(void)bin;
	if (!already_exist_key(start, add))
	{	
		last = my_lst_last(start);
		if (last)
			last->next = add;
		add->prev = last;
		if (bin && !bin->export)
			bin->export = add;
		if (bin && !bin->envp_lst && add->equal)
			bin->envp_lst = add;
		return (add);
	}
	return (NULL);
}

void	plus_func(t_mylst *add, t_mylst *current)
{
	if (add->plus)
	{
		current->value = ft_strjoin(current->value, add->value);
		free(add->value);
		add->value = NULL;
	}
}
