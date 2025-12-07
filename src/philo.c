/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:54 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 18:10:04 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_philo_fork(t_head *head)
{
	int	i;

	gettimeofday(&head->start_time, NULL);
	i = 0;
	while (i < head->number_philo)
	{
		head->philos[i].index = i + 1;
		head->philos[i].left = i;
		head->philos[i].right = (i + 1) % head->number_philo;
		head->philos[i].time = 100;
		head->philos[i].times_eaten = 0;
		head->philos[i].head = head;
		head->philos[i].last_meal = head->start_time;
		if (pthread_create(&head->philos[i].id, NULL, routine, (void *)&head->philos[i]) != 0)
			perror("pthread error");
		head->forks[i].index = i;
		if (pthread_mutex_init(&head->forks[i].fork, NULL) != 0)
			perror("mutex error");
		i++;
	}
	return (0);
}

int	wait_join(t_head *head)
{
	int	i;
	
	i = 0;
	while (i < head->number_philo)
	{
		pthread_join(head->philos[i].id, NULL);
		i++;
	}
	return (0);
}
