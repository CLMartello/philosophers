
#ifndef PHILOSOFERS_H

# define PHILOSOFERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_philo
{
	int			index;
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


#endif
