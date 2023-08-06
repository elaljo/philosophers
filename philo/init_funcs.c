/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:28 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/03 16:04:36 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_info_ph *info_ph, char *argv[], int argc)
{
	t_info_ph		ph_member[250];
	pthread_t		thread[250];
	pthread_mutex_t	forks[250];
	int				i;

	init_mutexes(info_ph, forks);
	i = 0;
	while (i < info_ph->num_ph)
	{
		init_members_of_threads(ph_member, argv, i, argc);
		give_forks_time_mem(info_ph, ph_member, i, forks);
		if (pthread_create(&thread[i], NULL, routine, &ph_member[i]) != 0)
			return ;
		usleep(5);
		i++;
	}
	main_thread_check(info_ph, ph_member);
}

void	main_thread_check(t_info_ph *info_ph, t_info_ph *ph_member)
{
	int	i;

	i = 0;
	while (1)
	{
		if (get_time() - ph_member[i].eat_time >= info_ph->t_die)
		{	
			printf("%04ld %d"RED" died\n"R, r_time(info_ph), ph_member[i].id);
			break ;
		}
		if (info_ph->eph_must_eat)
			if (ph_member[i].count_meals
				> info_ph->eph_must_eat * info_ph->num_ph + 1)
				break ;
	}
}

void	init_mutexes(t_info_ph *info_ph, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info_ph->num_forks)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	give_forks_time_mem(t_info_ph *info_ph, t_info_ph *ph_member,
	int i, pthread_mutex_t *forks)
{
		ph_member[i].leftfork = &forks[i];
		ph_member[i].rightfork = &forks[(i + 1) % info_ph->num_ph];
		ph_member[i].eat_time = get_time();
}

void	init_members_of_threads(t_info_ph *ph_member, char *s[],
	int i, int argc)
{
	ph_member[i].start_time = get_time();
	ph_member[i].id = i + 1;
	ph_member[i].count_meals = 0;
	ph_member[i].num_ph = ft_atoi(s[1]);
	ph_member[i].num_forks = ft_atoi(s[1]);
	ph_member[i].t_die = ft_atoi(s[2]);
	ph_member[i].t_eat = ft_atoi(s[3]);
	ph_member[i].t_sleep = ft_atoi(s[4]);
	if (argc == 6)
		ph_member[i].eph_must_eat = ft_atoi(s[5]);
}
