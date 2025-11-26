
#include "../include/philosophers.h"

void	time_to_sleep(t_head *head)
{
	usleep(head->time_to_sleep * 1000);
}

int	to_eat(t_head *head, t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = malloc(head->number_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	time_to_eat(head, philo, forks);
}
void	time_to_eat(t_head *head, t_philo *philo, pthread_mutex_t *forks)
{
	pthread_mutex_init(&forks[philo->index-1], NULL);
	pthread_mutex_init(&forks[philo->index+1], NULL);

	pthread_mutex_lock(&forks[philo->index-1]);
	pthread_mutex_lock(&forks[philo->index+1]);

	usleep(head->time_to_eat * 1000);

	pthread_mutex_unlock(&forks[philo->index-1]);
	pthread_mutex_unlock(&forks[philo->index+1]);

	pthread_mutex_destroy(&forks[philo->index-1]);
	pthread_mutex_destroy(&forks[philo->index+1]);
}
