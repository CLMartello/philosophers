
#include "../include/philosophers.h"

int	get_philo_right(t_head *head, int index)
{
	if (index == 1)
		return (head->number_philo);
	else
		return (index - 1);
}

int	get_philo_left(t_head *head, int index)
{
	if (index == head->number_philo)
		return (1);
	else
		return (index + 1);
}

int	init_philo(t_head *head)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < head->number_philo)
	{
		head->philos[i].index = j;
		head->philos[i].philo_left = get_philo_left(head, j);
		head->philos[i].philo_right = get_philo_right(head, j);
		//pthread_create(head->philos[i].id, NULL, NULL, NULL);
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
	head->philos = malloc(head->number_philo * sizeof(t_philo));
	if (!head->philos)
		return (0);
	head->time_to_die = ft_atoi(argv[2]);
	head->time_to_eat = ft_atoi(argv[3]);
	head->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		head->num_must_eat = ft_atoi(argv[5]);
	else
		head->num_must_eat = -1;
	init_philo(head);
	return (head);
}

void	ft_print_parse(t_head *head)
{
	int	i = 0;

	printf("number philo = %d\n", head->number_philo);
	while (i < head->number_philo)
	{
		printf("philo index = %d\n", head->philos[i].index);
		printf("philo to the right = %d\n", head->philos[i].philo_right);
		printf("philo to the left = %d\n", head->philos[i].philo_left);
		i++;
	}
	printf("time to die = %d\n", head->time_to_die);
	printf("time to eat = %d\n", head->time_to_eat);
	printf("time to sleep = %d\n", head->time_to_sleep);
	printf("number they must eat = %d\n", head->num_must_eat);
	printf("FIM!\n");
}
/*
void	parse(int argc, char *argv[])
{
	
}*/
