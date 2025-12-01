
#include "../include/philosophers.h"

void	free_all(t_head *head)
{
	if (head && head->philos)
		free(head->philos);
	if (head)
		free(head);
}
