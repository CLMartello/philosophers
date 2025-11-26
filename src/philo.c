
#include "../include/philosophers.h"

void	state_change(t_philo *philo)
{
	time_t	initial;

	gettimeofday(&initial, NULL);
	printf("TIME %d has taken a fork\n", philo->index);
	printf("TIME %d is eating\n", philo->index);
	printf("TIME %d is sleeping\n", philo->index);
	printf("TIME %d is thinking\n", philo->index);
	printf("TIME %d died", philo->index);
}
/*
void	ft_start(int argc, t_head *head)
{
	int	i = 0;

	while (i < head->number_philo)
	{
		if (head->philos->index % 2 == 0)
		{
			mutex(fork(index -1));
			mutex(fork(index +1));
			get_forks();
		}
		i++;
	}
}*/