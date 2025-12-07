/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:10 by clumertz          #+#    #+#             */
/*   Updated: 2025/12/07 18:10:19 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	int				time;
	int				times_eaten;
	struct timeval	last_meal;
	void			*head;
}					t_philo;

typedef struct s_head
{
	t_philo			*philos;
	t_fork			*forks;
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	pthread_mutex_t	print;
	int				print_flag;
	struct timeval	start_time;
	struct timeval	current_time;
	pthread_mutex_t	dead;
	int				dead_flag;
	

}					t_head;

//Functions
void	time_to_eat(t_head *head, t_philo *philo);
void	free_all(t_head *head);

//Parse
int		check_args(int argc, char **argv);
int		ft_atoi_philo(char *nptr);
t_head	*init_head(int argc, char *argv[]);

//Parse utils
void	ft_print_parse(t_head *head);

//Mutex utils
void	print_mutex(t_head *head, t_philo *philo, int time, char *message);

//Philo
int		init_philo_fork(t_head *head);
int	wait_join(t_head *head);

//Routine
void	*routine(void *arg);

#endif
