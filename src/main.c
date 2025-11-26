
#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_head *head;

	if (argc < 5 || argc > 6)
		return (0);
	head = init_head(argc, argv);
	/*ft_start(argc);
	if (head->time_to_die <= head->time_to_eat)
		philo_die();
	if (head->time_to_die <= (head->time_to_eat + head->time_to_sleep))
		philo_die();*/
	return (0);
}
