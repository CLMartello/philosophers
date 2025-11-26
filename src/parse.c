
#include "../include/philosophers.h"

int	init_philo(t_head *head)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < head->number_philo)
	{
		head->philos[i].index = j;
		//printf("esse e o philo %d com o index %d\n", i, j);
		pthread_create(head->philos[i].id, NULL, NULL, NULL);
		//pthread_join(head->philos[i].id, NULL);
		//pthread_detach(head->philos[i].id);
		i++;
		j++;
	}
	return (0);
}

t_head     *init_head(int argc, char *argv[])
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	if (!head)
		return (0);
	head->number_philo = ft_atoi(argv[1]);
//	head.number_forks = number_of_philo;
	head->philos = malloc(head->number_philo * sizeof(t_philo));
	if (!head->philos)
		return (0);
	head->time_to_die = ft_atoi(argv[2]);
	head->time_to_eat = ft_atoi(argv[3]);
	head->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		head->num_must_eat = ft_atoi(argv[5]);
	init_philo(head);
	return (0);
}
/*
void	parse(int argc, char *argv[])
{
	
}*/
