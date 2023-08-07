/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/03 16:15:25 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dest_free(t_info_ph *info_ph, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info_ph->num_forks)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(info_ph->time);
	pthread_mutex_destroy(info_ph->print);
	free(info_ph->time);
	free(info_ph->print);
}

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

void	*routine(void *info)
{
	t_info_ph	*info_ph;

	info_ph = (t_info_ph *)info;
	if (info_ph->id % 2)
		usleep(500);
	while (1)
	{
		print(info_ph, "is thinking");
		pthread_mutex_lock(info_ph->leftfork);
		print(info_ph, "has taken a fork");
		pthread_mutex_lock(info_ph->rightfork);
		print(info_ph, "has taken a fork");
		pthread_mutex_lock(info_ph->time);
		info_ph->eat_time = get_time();
		pthread_mutex_unlock(info_ph->time);
		eat_and_count_meals(info_ph);
		pthread_mutex_unlock(info_ph->leftfork);
		pthread_mutex_unlock(info_ph->rightfork);
		print(info_ph, "is sleeping");
		ft_usleep(info_ph->t_sleep);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_info_ph	info_ph;

	if ((argc == 5 || argc == 6))
	{
		if (if_valid(argv) == 0)
			return (1);
		init_philos_informations(&info_ph, argv, argc);
		init_threads(&info_ph, argv, argc);
		return (0);
	}
	print_err_args();
	return (1);
}
