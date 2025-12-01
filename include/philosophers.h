
#ifndef PHILOSOFERS_H

# define PHILOSOFERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int			index;
	int			philo_right;
	int			philo_left;
	pthread_t	id;
}		t_philo;

typedef struct	s_head
{
	t_philo	*philos;
	int	number_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}		t_head;

//Functions
int	ft_atoi(char *nptr);
t_head	*init_head(int argc, char *argv[]);
void	time_to_eat(t_head *head, t_philo *philo, pthread_mutex_t *forks);
void	ft_print_parse(t_head *head);
void	free_all(t_head *head);

#endif
