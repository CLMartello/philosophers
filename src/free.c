/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:16 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/13 16:27:49 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	free_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philo)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
}

void	free_all(t_table *table)
{
	if (table && table->philos)
		free(table->philos);
	if (table && table->forks)
	{
		free_mutex(table);
		free(table->forks);
	}
	if (table->print_flag == 1)
		pthread_mutex_destroy(&table->print);
	if (table->dead_flag > -1)
		pthread_mutex_destroy(&table->dead);
	if (table->eat_flag == 1)
		pthread_mutex_destroy(&table->eat);
	if (table)
		free(table);
}

void	ft_error(t_table *table, int error)
{
	if (error == 0)
		printf("Invalid number of arguments.\n");
	else if (error == 1)
		printf("Arguments must be positive numbers between 1 and INT_MAX.\n");
	else if (error == 2)
		printf("Malloc error.\n");
	else if (error == 3)
		printf("Mutex init error.\n");
	else if (error == 4)
		printf("Pthread create error.\n");
	else if (error == 5)
		printf("Pthread join error.\n");
	if (table)
		free_all(table);
}
