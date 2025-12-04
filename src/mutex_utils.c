/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/04 17:20:21 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_head *head, t_philo *philo, int time, char *message)
{
	pthread_mutex_lock(&head->print);
	printf("%d %d %s", time, philo.index, message);
	pthread_mutex_unlock(&head->print);
}
