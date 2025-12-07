/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:16 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 16:02:51 by clumertz         ###   ########.fr       */
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
