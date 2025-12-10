/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:41 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:56 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	ft_atoi_philo(char *number)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	if (number[0] == '+')
		i++;
	while (number[i] != '\0' && i < 12)
	{
		if (number[i] >= '0' && number[i] <= '9')
			value = value * 10 + (number[i] - '0');
		else
			return (-1);
		i++;
	}
	if (value > INT_MAX || i >= 12)
		return (-1);
	return (value);
}
