/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:38:41 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/04 16:49:28 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi_philo(char *number)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (number[i] != '\0')
	{
		if (number[i] >= '0' && number[i] <= '9')
			value = value * 10 + (number[i] - '0');
		else
			return (-1);
		i++;
	}
	return (value);
}
