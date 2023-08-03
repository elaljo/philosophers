/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:42 by moelalj           #+#    #+#             */
/*   Updated: 2023/07/30 12:31:43 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_atoi(char *s)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while	(s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			sign = sign * -1;
			i++;
		}
		else
			break;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - '0';
		else
			break;
		i++;
	}
	return (res * sign);
}
