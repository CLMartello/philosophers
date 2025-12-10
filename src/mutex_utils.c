/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 17:06:59 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_table *table, t_philo *philo, int time, char *message)
{
	if (is_dead(table) == 1)
		return ;
	pthread_mutex_lock(&table->print);
	printf("%d %d %s", time, philo->index, message);
	pthread_mutex_unlock(&table->print);
}

int	is_dead(t_table *table)
{
	int	value;

	pthread_mutex_lock(&table->dead);
	value = table->dead_flag;
	pthread_mutex_unlock(&table->dead);
	return (value);
}

int	have_philo_eat(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philo)
	{
		if (table->num_must_eat > table->philos[i].times_eaten)
			return (0);
	}
	return (1);
}

int	monitor(t_table *table)
{
	long	timestamp;
	int		i;

	while (is_dead(table) != 1)
	{
		i = 0;
		while (i < table->number_philo)
		{
			pthread_mutex_lock(&table->eat);
			timestamp = get_time(table) - table->philos[i].last_meal;
			pthread_mutex_unlock(&table->eat);
			if (timestamp >= table->time_to_die)
			{
				print_mutex(table, &table->philos[i], get_timestamp(table),
					"died\n");
				pthread_mutex_lock(&table->dead);
				table->dead_flag = 1;
				pthread_mutex_unlock(&table->dead);
				break ;
			}
			if (table->num_must_eat != -1)
			{
				if (is_philo_satisfied(table) == 1)
					break ;
			}
			i++;
		}
		//usleep(1000);
	}
	return (0);
}

int	is_philo_satisfied(t_table *table)
{
	int	i;
	int	value;

	i = 0;
	value = 1;
	while (i < table->num_must_eat)
	{
		pthread_mutex_lock(&table->eat);
		if (table->philos[i].times_eaten <= table->num_must_eat)
			value = 0;
		pthread_mutex_unlock(&table->eat);
		i++;
	}
	if (value == 1)
	{
		pthread_mutex_lock(&table->dead);
		table->dead_flag = 1;
		pthread_mutex_unlock(&table->dead);
	}
	return (value);
}