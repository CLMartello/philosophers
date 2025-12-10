/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:10 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/10 17:06:59 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	int				index;
	pthread_mutex_t	fork;
}					t_fork;

typedef struct s_philo
{
	int				index;
	int				right;
	int				left;
	pthread_t		id;
	int				times_eaten;
	long			last_meal;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_fork			*forks;
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	struct timeval	start_time;
	struct timeval	current_time;
	pthread_mutex_t	print;
	int				print_flag;
	pthread_mutex_t	dead;
	int				dead_flag;
	pthread_mutex_t	eat;
	int				eat_flag;
}					t_table;

//Parse
int		check_args(int argc, char **argv);
t_table	*init_table(int argc, char *argv[]);

//Parse utils
long	ft_atoi_philo(char *number);

//Mutex utils
void	print_mutex(t_table *table, t_philo *philo, int time, char *message);
int		monitor(t_table *table);
int		is_dead(t_table *table);
int		is_philo_satisfied(t_table *table);

//Philo
int		init_philo_fork(t_table *table);
int		wait_join(t_table *table);

//Routine
void	*routine(void *arg);

//Routine utils
long	get_time(t_table *table);
long	get_timestamp(t_table *table);
int		decide_first_fork(t_philo *philo);
int		decide_second_fork(t_philo *philo);

//Free
void	free_all(t_table *table);
void	ft_error(t_table *table, int error);

#endif
