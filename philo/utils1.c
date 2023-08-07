/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:17:08 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/03 16:21:07 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_count_meals(t_info_ph *info_ph)
{
	static int	meals;

	print(info_ph, "is eating");
	pthread_mutex_lock(info_ph->time);
	meals++;
	info_ph->count_meals = meals;
	pthread_mutex_unlock(info_ph->time);
	ft_usleep(info_ph->t_eat);
}

void	print(t_info_ph *info_ph, char *msg)
{
	pthread_mutex_lock(info_ph->print);
	printf("%04ld %d %s\n", r_time(info_ph), info_ph->id, msg);
	pthread_mutex_unlock(info_ph->print);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int time_to_sleep)
{
	long	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= time_to_sleep)
			break ;
		usleep(200);
	}
}

long	r_time(t_info_ph *info_ph)
{
	return (get_time() - info_ph->start_time);
}
