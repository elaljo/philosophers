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

void	init_philos_informations(t_info_ph *info, char **argv, int argc)
{
	info->start_time = get_time();
	info->count_meals = 0;
	info->num_ph = ft_atoi(argv[1]);
	info->num_forks = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->eph_must_eat = ft_atoi(argv[5]);
}

void	init_threads(t_info_ph *info_ph, char *argv[], int argc)
{
	t_info_ph		ph_member[250];
	pthread_t		thread[250];
	pthread_mutex_t	forks[250];
	int				i;

	i = 0;
	while (i < info_ph->num_ph)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < info_ph->num_ph)
	{
		init_members_of_threads(ph_member, argv, i, argc);
		ph_member[i].leftfork = &forks[i];
		ph_member[i].rightfork = &forks[(i + 1) % info_ph->num_forks];
		ph_member[i].eat_time = get_time();
		if (pthread_create(&thread[i], NULL, routine, &ph_member[i]) != 0)
			return ;
		usleep(10);
		i++;
	}
	i = 0;
	while (1)
	{
		if (get_time() - ph_member[i].eat_time >= info_ph->t_die)
		{	
			printf("%04ld %d"RED" died\n"R, get_time() - info_ph->start_time,
				ph_member[i].id);
			break ;
		}
		if ((ph_member[i].count_meals > (info_ph->eph_must_eat * info_ph->num_ph)) && info_ph->eph_must_eat)
			break ;
		i++;
		if (i >= info_ph->num_ph)
			i = 0;
	}
}


void	init_members_of_threads(t_info_ph *ph_member, char *s[], int i, int argc)
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
