/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:53 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/13 19:57:15 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	time_to_sleep(t_table *table, t_philo *philo)
{
	long	time;

	time = table->time_to_sleep;
	if (is_dead(table) == 1)
		return ;
	print_mutex(table, philo, get_timestamp(table), "is sleeping\n");
	if (table->time_to_sleep > table->time_to_die)
		time = table->time_to_die;
	usleep(time * 1000);
}

static void	time_to_think(t_table *table, t_philo *philo)
{
	if (is_dead(table) == 1)
		return ;
	print_mutex(table, philo, get_timestamp(table), "is thinking\n");
}

static void	time_to_eat(t_table *table, t_philo *philo)
{
	long	time;

	time = table->time_to_eat;
	if (is_dead(table) == 1)
		return ;
	print_mutex(table, philo, get_timestamp(table), "is eating\n");
	pthread_mutex_lock(&table->eat);
	philo->last_meal = get_time(table);
	philo->times_eaten++;
	pthread_mutex_unlock(&table->eat);
	if (table->time_to_eat > table->time_to_die)
		time = table->time_to_die;
	usleep(time * 1000);
}

static void	take_forks(t_table *table, t_philo *philo)
{
	if (is_dead(table) == 1)
		return ;
	pthread_mutex_lock(&table->forks[decide_first_fork(philo)].fork);
	print_mutex(table, philo, get_timestamp(table), "has taken a fork\n");
	pthread_mutex_lock(&table->forks[decide_second_fork(philo)].fork);
	print_mutex(table, philo, get_timestamp(table), "has taken a fork\n");
	time_to_eat(table, philo);
	pthread_mutex_unlock(&table->forks[decide_second_fork(philo)].fork);
	pthread_mutex_unlock(&table->forks[decide_first_fork(philo)].fork);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *) arg;
	if (philo->table->number_philo == 1)
		only_one_philo(philo->table);
	if (philo->index % 2 != 0)
		usleep(1000);
	while (1)
	{
		if (is_dead(philo->table) == 1)
			break ;
		take_forks(philo->table, philo);
		time_to_sleep(philo->table, philo);
		time_to_think(philo->table, philo);
		if (philo->table->number_philo % 2 != 0 && philo->index % 2 != 0)
			usleep(1000);
	}
	return (NULL);
}
