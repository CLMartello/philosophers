/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:38 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/13 14:02:49 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(t_table *table)
{
	long	time;

	gettimeofday(&table->current_time, NULL);
	time = (table->current_time.tv_sec * 1000)
		+ (table->current_time.tv_usec / 1000);
	return (time);
}

long	get_timestamp(t_table *table)
{
	long	timestamp;

	timestamp = get_time(table) - ((table->start_time.tv_sec * 1000)
			+ (table->start_time.tv_usec / 1000));
	return (timestamp);
}

int	decide_first_fork(t_philo *philo) //min
{
	if (philo->index % 2 == 0)
		return (philo->left);
	else
		return (philo->right);
}

int	decide_second_fork(t_philo *philo) //max
{
	if (philo->index % 2 == 0)
		return (philo->right);
	else
		return (philo->left);
}

void	only_one_philo(t_table *table)
{
	print_mutex(table, &table->philos[0], get_timestamp(table),
		"has taken a fork\n");
	usleep(table->time_to_die * 1000);
	print_mutex(table, &table->philos[0], get_timestamp(table), "died\n");
	pthread_mutex_lock(&table->dead);
	table->dead_flag = 1;
	pthread_mutex_unlock(&table->dead);
}
