/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:55 by moelalj           #+#    #+#             */
/*   Updated: 2023/07/30 12:31:57 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_valid(char **s)
{
	int i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] >= '0' && s[i][j] <= '9') && ft_atoi(s[3]) >= 60 && ft_atoi(s[4]) >= 60)
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

void	print_err_args()
{
	printf(RED"WRONG INPUT"RESET" -- Numbers of arguments is not enough\n");
	printf(GREEN"  					! REMINDER OF ENOUGH ARGUMENTS !\n"RESET);
	printf("[number_of_philosophers] - [time_to_die] - [time_to_eat]");
	printf(" - [time_to_sleep] - [number_of_times_each_philosopher_must_eat]");
	printf("(Optional argument)\n");
}
