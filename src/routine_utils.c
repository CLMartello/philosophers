/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:38 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 15:44:37 by clumertz         ###   ########.fr       */
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
	long	start_time;
	long	timestamp;

	start_time = (table->start_time.tv_sec * 1000)
		+ (table->start_time.tv_usec / 1000);
	timestamp = get_time(table) - start_time;
	return (timestamp);
}

int	decide_first_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		return (philo->left);
	else
		return (philo->right);
}

int	decide_second_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		return (philo->right);
	else
		return (philo->left);
}
