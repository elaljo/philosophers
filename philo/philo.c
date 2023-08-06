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

void	*routine(void *info)
{
	t_info_ph	*info_ph;

	info_ph = (t_info_ph *)info;
	if (info_ph->id % 2)
		usleep(100);
	while (1)
	{
		printf("%04ld %d is "GREEN"thinking\n"R, get_time() - info_ph->start_time, info_ph->id);
		pthread_mutex_lock(info_ph->leftfork);
		printf("%04ld %d has taken a "CYAN"fork\n"R, get_time() - info_ph->start_time, info_ph->id);
		pthread_mutex_lock(info_ph->rightfork);
		printf("%04ld %d has taken a "CYAN"fork\n"R, get_time() - info_ph->start_time, info_ph->id);
		info_ph->eat_time = get_time();
		eat_and_count_meals(info_ph);
		pthread_mutex_unlock(info_ph->leftfork);
		pthread_mutex_unlock(info_ph->rightfork);
		printf("%04ld %d is "YELLOW"sleeping\n"R, get_time() - info_ph->start_time, info_ph->id);
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
