/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:16 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 18:00:01 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_mutex(t_head *head)
{
	int	i;

	i = 0;
	while (i < head->number_philo)
	{
		pthread_mutex_destroy(&head->forks[i].fork);
		i++;
	}
}

void	free_all(t_head *head)
{
	if (head && head->philos)
		free(head->philos);
	if (head && head->forks)
	{
		free_mutex(head);
		free(head->forks);
	}
	if (head->print_flag == 1)
	 	pthread_mutex_destroy(&head->print);
	if (head)
		free(head);
}

void	ft_error(t_head *head, int error)
{
	if (error == 0)
		printf("Invalid number of arguments.\n");
	else if (error == 1)
		printf("Arguments must be positive numbers between 0 and INT_MAX.\n");
	else if (error == 2)
		printf("Malloc error.\n");
	else if (error == 3)
		printf("Mutex init error.\n");
	else if (error == 4)
		printf("Pthread create error.\n");
	else if (error == 5)
		printf("Pthread join error.\n");
	if (head)
		free_all(head);
	
}