/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:41 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 15:26:18 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print_parse(t_head *head)
{
	int	i;

	i = 0;
	printf("number philo = %d\n", head->number_philo);
	while (i < head->number_philo)
	{
		printf("philo index = %d\n", head->philos[i].index);
		printf("philo to the right = %d\n", head->philos[i].right);
		printf("philo to the left = %d\n", head->philos[i].left);
		i++;
	}
	printf("time to die = %d\n", head->time_to_die);
	printf("time to eat = %d\n", head->time_to_eat);
	printf("time to sleep = %d\n", head->time_to_sleep);
	printf("number they must eat = %d\n", head->num_must_eat);
	printf("FIM!\n");
}
