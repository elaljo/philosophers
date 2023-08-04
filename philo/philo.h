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
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define CYAN    "\x1B[36m"
# define RESET   "\x1B[0m"

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
void	init_members_of_threads(t_info_ph *ph_member, char *s[], int i, int argc);
void	eat_and_count_meals(t_info_ph *info_ph);
void	ft_usleep(int time_to_sleep);
//int		eph_must_eat(t_info_ph *info_ph, t_info_ph *ph_member);
int		ft_atoi(char *s);
int		if_valid(char **s);

#endif
