/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:17:08 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/01 19:17:10 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_count_meals(t_info_philos *info_philos)
{
	printf("%04ld %d is "BLUE"eating\n"RESET, get_time() - info_philos->start_time,  info_philos->id);
	info_philos->count_meals++;
}

long	get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int time_to_sleep ,t_info_philos *info_philos)
{
	(void)info_philos;
	long	start = get_time();
	while (1)
	{
		if(get_time() - start >= time_to_sleep)
			break ;
		usleep(500);
	}
}
