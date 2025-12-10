/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:30 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 16:58:04 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (check_args(argc, argv) == 1)
		return (1);
	table = init_table(argc, argv);
	init_philo_fork(table);
	monitor(table);
	wait_join(table);
	free_all(table);
	return (0);
}
