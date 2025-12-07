/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:53 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 18:14:01 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_timestamp(t_head *head)
{
	long	timestamp;
	
	gettimeofday(&head->current_time, NULL);
	timestamp = ((head->current_time.tv_sec - head->start_time.tv_sec) * 1000 +
		(head->current_time.tv_usec - head->start_time.tv_usec) / 1000);
	return (timestamp);
}

void	time_to_sleep(t_head *head, t_philo *philo)
{
	long	timestamp;
	
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "is sleeping\n");
	usleep(head->time_to_sleep * 1000);
}

void	time_to_think(t_head *head, t_philo *philo)
{
	long	timestamp;
	
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "is thinking\n");
}

void	time_to_eat(t_head *head, t_philo *philo)
{
	long	timestamp;

	//uptade last_meal before usleep?
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "is eating\n");
	usleep(head->time_to_eat * 1000);
	gettimeofday(&philo->last_meal, NULL);
	philo->times_eaten++;
}

void	take_forks(t_head *head, t_philo *philo)
{
	long	timestamp;

	pthread_mutex_lock(&head->forks[philo->left].fork);
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "has taken a fork\n");
	pthread_mutex_lock(&head->forks[philo->right].fork);
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "has taken a fork\n");
	time_to_eat(head, philo);
	pthread_mutex_unlock(&head->forks[philo->left].fork);
	pthread_mutex_unlock(&head->forks[philo->right].fork);
}

int	is_philo_dead(t_head *head, t_philo *philo)
{
	long	timestamp;
	
	gettimeofday(&head->current_time, NULL);
	timestamp = (head->current_time.tv_sec * 1000 + head->current_time.tv_usec / 1000)
					- (philo->last_meal.tv_sec * 1000 + philo->last_meal.tv_usec / 1000);
	if (timestamp >= head->time_to_die)
		head->dead_flag = 1;
	return (0);
}

void	call_death(t_head *head, t_philo *philo)
{
	long	timestamp;

	usleep(10000);
	timestamp = get_timestamp(head);
	print_mutex(head, philo, timestamp, "died\n");
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->index % 2 != 0)
			usleep(1000);
		take_forks(philo->head, philo);
		time_to_sleep(philo->head, philo);
		time_to_think(philo->head, philo);
		if (is_philo_dead(philo->head, philo) == 1)
		{
			call_death(philo->head, philo);
			break;
		}
	}
	return (NULL);
}
