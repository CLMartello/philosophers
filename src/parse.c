/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:45:59 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 17:57:11 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	init_mutex(t_head *head)
{
	if (pthread_mutex_init(&head->print, NULL) != 0)
	{
		ft_error(head, 3);
		return ;
	}
	head->print_flag = 1;
	if (pthread_mutex_init(&head->dead, NULL) != 0)
	{
		ft_error(head, 3);
		return ;
	}
	head->dead_flag = 0;
}

t_head	*init_head(int argc, char *argv[])
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	if (!head)
		ft_error(NULL, 2);
	head->number_philo = ft_atoi_philo(argv[1]);
	head->philos = malloc(head->number_philo * sizeof(t_philo));
	if (!head->philos)
		ft_error(head, 2);
	head->forks = malloc(head->number_philo * sizeof(t_fork));
	if (!head->forks)
		ft_error(head, 2);
	head->time_to_die = ft_atoi_philo(argv[2]);
	head->time_to_eat = ft_atoi_philo(argv[3]);
	head->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argc == 6)
		head->num_must_eat = ft_atoi_philo(argv[5]);
	else
		head->num_must_eat = -1;
	head->dead_flag = -1;
	init_mutex(head);
	return (head);
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
