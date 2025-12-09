/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:38:41 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/09 15:25:01 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	ft_atoi_philo(char *number)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	while (number[i] != '\0' && i < 11)
	{
		if (number[0] == '+')
			i++;
		if (number[i] >= '0' && number[i] <= '9')
			value = value * 10 + (number[i] - '0');
		else
			return (-1);
		i++;
	}
	if (value > INT_MAX || i >= 11)
		return (-1);
	return (value);
}
