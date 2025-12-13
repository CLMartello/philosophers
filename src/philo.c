/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:54 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/13 13:52:37 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	start_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_create(&table->philos[i].id, NULL, routine,
				&table->philos[i]) != 0)
			ft_error(table, 4);
		i++;
	}
}

int	init_philo_fork(t_table *table)
{
	int	i;

	gettimeofday(&table->start_time, NULL);
	i = 0;
	while (i < table->number_philo)
	{
		table->philos[i].index = i + 1;
		table->philos[i].left = i;
		table->philos[i].right = (i + 1) % table->number_philo;
		table->philos[i].times_eaten = 0;
		table->philos[i].table = table;
		table->philos[i].last_meal = get_time(table);
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
			ft_error(table, 3);
		table->forks[i].index = i;
		i++;
	}
	start_threads(table);
	return (0);
}

int	wait_join(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philo)
	{
		if (pthread_join(table->philos[i].id, NULL) != 0)
			ft_error(table, 5);
		i++;
	}
	return (0);
}
