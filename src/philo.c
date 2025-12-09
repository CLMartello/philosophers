/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:54 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 18:00:13 by clumertz         ###   ########.fr       */
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
		head->philos[i].last_meal = get_time(head);
		if (pthread_create(&head->philos[i].id, NULL, routine, &head->philos[i]) != 0)
			ft_error(head, 4);	
		head->forks[i].index = i;
		if (pthread_mutex_init(&head->forks[i].fork, NULL) != 0)
			ft_error(head, 3);
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
		if (pthread_join(head->philos[i].id, NULL) != 0)
		{
			ft_error(head, 5);
		}
		i++;
	}
	return (0);
}
