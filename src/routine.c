/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:53 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 17:50:08 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(t_head *head)
{
	
	long	time;
	
	gettimeofday(&head->current_time, NULL);
	time = (head->current_time.tv_sec * 1000) + (head->current_time.tv_usec / 1000);
	return (time);
}

long	get_timestamp(t_head *head)
{
	long	start_time;
	long	timestamp;
	
	start_time = (head->start_time.tv_sec * 1000) + (head->start_time.tv_usec / 1000);
	timestamp = get_time(head) - start_time;
	return (timestamp);
}

void	time_to_sleep(t_head *head, t_philo *philo)
{
	if (head->dead_flag == 1)
		return ;
	print_mutex(head, philo, get_timestamp(head), "is sleeping\n");
	usleep(head->time_to_sleep * 1000);
}

void	time_to_think(t_head *head, t_philo *philo)
{
	if (head->dead_flag == 1)
		return ;
	print_mutex(head, philo, get_timestamp(head), "is thinking\n");
}

void	time_to_eat(t_head *head, t_philo *philo)
{
	if (head->dead_flag == 1)
		return ;
	print_mutex(head, philo, get_timestamp(head), "is eating\n");
	philo->last_meal = get_time(head);
	usleep(head->time_to_eat * 1000);
	philo->times_eaten++;
}

void	take_forks(t_head *head, t_philo *philo)
{
	if (head->dead_flag == 1)
		return ;
	pthread_mutex_lock(&head->forks[philo->left].fork);
	print_mutex(head, philo, get_timestamp(head), "has taken a fork\n");
	pthread_mutex_lock(&head->forks[philo->right].fork);
	print_mutex(head, philo, get_timestamp(head), "has taken a fork\n");
	time_to_eat(head, philo);
	pthread_mutex_unlock(&head->forks[philo->left].fork);
	pthread_mutex_unlock(&head->forks[philo->right].fork);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *) arg;
	if (philo->index % 2 != 0)
		usleep(1000);
	while (1)
	{
		if (philo->head->dead_flag == 1)
			break ;
		take_forks(philo->head, philo);
		time_to_sleep(philo->head, philo);
		time_to_think(philo->head, philo);
	}
	return (NULL);
}
