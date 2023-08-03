/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:28 by moelalj           #+#    #+#             */
/*   Updated: 2023/07/30 12:31:30 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_info_philos *info_philos, char *argv[], int argc)
{
		t_info_philos	philos_members[info_philos->num_of_philos];
		pthread_t			thread[info_philos->num_of_philos];
		pthread_mutex_t forks[info_philos->num_of_forks];
		
		int	i;

		i = 0;
		while(i < info_philos->num_of_philos)
		{
			pthread_mutex_init(&forks[i], NULL);
			i++;
		}
		
		pthread_mutex_init(&info_philos->tm, NULL);
		i = 0;
		while (i < info_philos->num_of_philos)
		{
			init_members_of_threads(philos_members, argv, i, argc);
			philos_members[i].leftfork = &forks[i];
			philos_members[i].rightfork = &forks[(i + 1) % info_philos->num_of_forks];
			philos_members[i].eat_time = get_time(info_philos);
			if (pthread_create(&thread[i], NULL, routine, &philos_members[i]) != 0)
				return;
			usleep(50);
			i++;
		}
		
		i = 0;
		int count_philos;
		int	 count_eat;
		while (1)
		{
			if (get_time() - philos_members[i].eat_time >= info_philos->t_to_die)
			{
	 			printf("%04ld %d"RED" died\n"RESET, get_time() - info_philos->start_time, philos_members[i].id);
				break;
			}
			if (info_philos->num_o_t_each_ph_must_eat)
			{
				count_eat = 0;
				count_philos = 0;
				while (count_philos < info_philos->num_of_philos)
				{
					if (philos_members[count_philos].count_meals == info_philos->num_o_t_each_ph_must_eat)
						count_eat++;
					count_philos++;
				}
				if (count_eat == info_philos->num_of_philos)
					break;
			}
			i++;
			if (i >= info_philos->num_of_philos)
				i = 0;
		}
}

void	init_philos_informations(t_info_philos *info, char **argv, int argc)
{
		info->start_time = get_time(info);
		info->count_meals = 0;
		info->num_of_philos = ft_atoi(argv[1]);
		info->num_of_forks = ft_atoi(argv[1]);
		info->t_to_die = ft_atoi(argv[2]);
		info->t_to_eat = ft_atoi(argv[3]);
		info->t_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			info->num_o_t_each_ph_must_eat = ft_atoi(argv[5]);
}

void	init_members_of_threads(t_info_philos *philos_members, char *s[], int i, int argc)
{
	philos_members[i].start_time = get_time(philos_members);
	philos_members[i].id = i + 1;
	philos_members[i].count_meals = 0;
	philos_members[i].num_of_philos = ft_atoi(s[1]);
	philos_members[i].num_of_forks = ft_atoi(s[1]);
	philos_members[i].t_to_die = ft_atoi(s[2]);
	philos_members[i].t_to_eat = ft_atoi(s[3]);
	philos_members[i].t_to_sleep = ft_atoi(s[4]);
	if (argc == 6)
		philos_members[i].num_o_t_each_ph_must_eat = ft_atoi(s[5]);
}
