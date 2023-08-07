/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:09:05 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/03 16:09:06 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED     "\x1B[31m"
# define R   "\x1B[0m"

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info_ph
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*time;
	pthread_mutex_t	*print;
	int				id;
	int				num_ph;
	int				num_forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	long			start_time;
	int				eph_must_eat;
	int				count_meals;
	long			eat_time;
}t_info_ph;

long	get_time(void);
void	print_err_args(void);
void	*routine(void *info);
void	init_philos_informations(t_info_ph *info, char **argv, int argc);
void	init_threads(t_info_ph *info_ph, char *argv[], int argc);
void	init_members_of_threads(t_info_ph *ph_member, char *s[],
			int i, int argc);
void	give_forks_time_mem(t_info_ph *info_ph, t_info_ph *ph_member,
			int i, pthread_mutex_t *forks);
void	main_thread_check(t_info_ph *info_ph, t_info_ph *ph_member,
			pthread_mutex_t *forks);
int		init_mutexes(t_info_ph *info_ph, pthread_mutex_t *forks);
void	eat_and_count_meals(t_info_ph *info_ph);
void	ft_usleep(int time_to_sleep);
int		ft_atoi(char *s);
int		if_valid(char **s);
long	r_time(t_info_ph *info_ph);
void	print(t_info_ph *info_ph, char *msg);
void	dest_free(t_info_ph *info_ph, pthread_mutex_t *forks);

#endif
