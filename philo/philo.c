/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/07/31 16:00:48 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *info)
{
		t_info_philos *info_philos;

		info_philos = (t_info_philos *)info;
		if (info_philos->id % 2)
			usleep(100);
		while (1)
		{
			printf("%04ld %d is "GREEN"thinking\n"RESET, get_time() - info_philos->start_time, info_philos->id);
			pthread_mutex_lock(info_philos->leftfork);
	 		printf("%04ld %d has taken a "CYAN"fork\n"RESET, get_time() - info_philos->start_time, info_philos->id);
			pthread_mutex_lock(info_philos->rightfork);
	 		printf("%04ld %d has taken a "CYAN"fork\n"RESET, get_time() - info_philos->start_time, info_philos->id);
			eat_and_count_meals(info_philos);
			pthread_mutex_lock(&info_philos->tm);
			info_philos->eat_time = get_time();
			pthread_mutex_unlock(&info_philos->tm);
			ft_usleep(info_philos->t_to_eat, info_philos);
			pthread_mutex_unlock(info_philos->leftfork);
			pthread_mutex_unlock(info_philos->rightfork);
	 		printf("%04ld %d is "YELLOW"sleeping\n"RESET, get_time() - info_philos->start_time, info_philos->id);
			ft_usleep(info_philos->t_to_sleep, info_philos);
		}
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_info_philos info_philos;

	if ((argc == 5 || argc == 6))
	{
		if (if_valid(argv) == 0)
			return (1);
		init_philos_informations(&info_philos, argv, argc);
		init_threads(&info_philos, argv, argc);
		return (0);
	}
	print_err_args();
	return (1);
}
