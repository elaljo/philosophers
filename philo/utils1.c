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

	printf("%04ld %d is "BLUE"eating\n"R, get_time() - info_ph->start_time, info_ph->id);
	meals++;
	info_ph->count_meals = meals; 
	ft_usleep(info_ph->t_eat);
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
