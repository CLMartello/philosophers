/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:49:30 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 18:11:17 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_head	*head;

	if (check_args(argc, argv) == 1)
		return (1);
	head = init_head(argc, argv);
	init_philo_fork(head);
	//ft_print_parse(head);
	wait_join(head);
	free_all(head);
	return (0);
}
