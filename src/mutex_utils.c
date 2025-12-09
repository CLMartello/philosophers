/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 17:51:29 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_head *head, t_philo *philo, int time, char *message)
{
	pthread_mutex_lock(&head->print);
	printf("%d %d %s", time, philo->index, message);
	pthread_mutex_unlock(&head->print);
}

int	monitor_dead(t_head *head)
{
	long	time;
	long	timestamp;
	int		i;
	
	pthread_mutex_lock(&head->dead);
	time = get_time(head);
	while (1)
	{
		i = 0;
		while (i < head->number_philo)
		{
			timestamp = time - head->philos[i].last_meal;
			if (timestamp >= head->time_to_die)
			{
				print_mutex(head, &head->philos[i], get_timestamp(head), "died\n");
				head->dead_flag = 1;
				pthread_mutex_unlock(&head->dead);
				return (1);
			}
			i++;
		}
		usleep(1000);
	}
	pthread_mutex_unlock(&head->dead);
	return (0);
}