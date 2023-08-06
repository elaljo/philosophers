/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:55 by moelalj           #+#    #+#             */
/*   Updated: 2023/08/03 15:47:14 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_valid(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (((s[i][j] >= '0' && s[i][j] <= '9') && ft_atoi(s[3]) >= 60 &&
			ft_atoi(s[4]) >= 60) && ft_atoi(s[1]) <= 250)
				j++;
			else
			{
				printf("Unvalidated arguments!!\n 	try again");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	print_err_args(void)
{
	printf(RED"WRONG INPUT"R" -- Numbers of arguments is not enough\n");
	printf(GREEN"  					! REMINDER OF ENOUGH ARGUMENTS !\n"R);
	printf("[number_of_philosophers] - [time_to_die] - [time_to_eat]");
	printf(" - [time_to_sleep] - ");
	printf("[number_of_times_each_philosopher_eph_must_eat]");
	printf("(Optional argument)\n");
}

int	ft_atoi(char *s)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = sign * -1;
		else
			break ;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - '0';
		else
			break ;
		i++;
	}
	return (res * sign);
}
