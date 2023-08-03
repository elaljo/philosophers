#ifndef PHILO_H
# define PHILO_H

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define CYAN    "\x1B[36m"
#define RESET   "\x1B[0m"

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_info_philos
{
	pthread_mutex_t *forks;
	pthread_mutex_t *leftfork;
	pthread_mutex_t *rightfork;
	pthread_mutex_t *print;
	pthread_mutex_t	tm;
	 
	int	id;
	int	num_of_philos;
	int	num_of_forks;
	int t_to_die;
	int	t_to_eat;
	int t_to_sleep;
	long	start_time;
	int	num_o_t_each_ph_must_eat;
	int	count_meals;
	long	eat_time;
}	t_info_philos;

long	get_time();
void	print_err_args();
void	*routine(void *info);
void	init_philos_informations(t_info_philos *info, char **argv, int argc);
void	init_threads(t_info_philos *info_philos, char *argv[], int argc);
void	init_members_of_threads(t_info_philos *philos_members, char *s[], int i, int argc);
void	eat_and_count_meals(t_info_philos *info_philos);
void	ft_usleep(int time_to_sleep ,t_info_philos *info_philos);

//  casses
int	only_one_ph(t_info_philos *info_philos);

//--------------helper_funcs
int ft_atoi(char *s);


// check_args
int	if_valid(char **s);

#endif