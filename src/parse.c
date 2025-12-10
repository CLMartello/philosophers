/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:59 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 17:04:47 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		ft_error(table, 3);
		return ;
	}
	table->print_flag = 1;
	if (pthread_mutex_init(&table->dead, NULL) != 0)
	{
		ft_error(table, 3);
		return ;
	}
	table->dead_flag = 0;
	if (pthread_mutex_init(&table->eat, NULL) != 0)
	{
		ft_error(table, 3);
		return ;
	}
	table->eat_flag = 1;
}

t_table	*init_table(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		ft_error(NULL, 2);
	table->number_philo = ft_atoi_philo(argv[1]);
	table->philos = malloc(table->number_philo * sizeof(t_philo));
	if (!table->philos)
		ft_error(table, 2);
	table->forks = malloc(table->number_philo * sizeof(t_fork));
	if (!table->forks)
		ft_error(table, 2);
	table->time_to_die = ft_atoi_philo(argv[2]);
	table->time_to_eat = ft_atoi_philo(argv[3]);
	table->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argc == 6)
		table->num_must_eat = ft_atoi_philo(argv[5]);
	else
		table->num_must_eat = -1;
	table->dead_flag = -1;
	init_mutex(table);
	return (table);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_error(NULL, 0);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_philo(argv[i]) == -1)
		{
			ft_error(NULL, 1);
			return (1);
		}
		i++;
	}
	return (0);
}
