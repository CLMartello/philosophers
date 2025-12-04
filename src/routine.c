/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:53 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/04 17:23:21 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	time_to_sleep(t_head *head, t_philo *philo)
{
	
	usleep(head->time_to_sleep * 1000);
	philo->time += head->time_to_sleep;
	print_mutex(head, philo, philo->time, "is thinking\n");
}

void	time_to_think(t_head *head, t_philo *philo)
{
	print_mutex(head, philo, philo->time, "is thinking\n");
}

void	time_to_eat(t_head *head, t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&head->forks[philo->left].fork);
	print_mutex(head, philo, philo->time, "has taken a fork\n");
	pthread_mutex_lock(&head->forks[philo->right].fork);
	print_mutex(head, philo, philo->time, "has taken a fork\n");
	usleep(head->time_to_eat * 1000);
	philo->time += head->time_to_eat;
	print_mutex(head, philo, philo->time, "is eating\n");
	philo->times_eaten++;
	pthread_mutex_unlock(&head->forks[philo->left].fork);
	pthread_mutex_unlock(&head->forks[philo->right].fork);
}

void	routine(void *arg)
{
	struct timeval	time;
	t_philo			*philo;
	t_head			*head;

	gettimeofday(&time, NULL);
	philo = (t_philo *)arg;
	head = (t_head *)philo->head;
	philo->time = 0;
	if (philo->index % 2 == 0)
	{
		time_to_eat(philo->head, philo);
		time_to_think(philo->head, philo);
		time_to_sleep(philo->head, philo);
	}
	else if (philo->head.number_philo % 2 != 0)
	{
		time_to_think(philo->head, philo);
		time_to_sleep(philo->head, philo);
		time_to_eat(philo->head, philo);
	}
	//usleep(1000);
}
