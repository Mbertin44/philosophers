/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:50:15 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/08 13:44:20 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	parsing(t_vault *data)
{
	if (check_argc(data) == true && check_param_is_digit(data) == true
		&& check_param_len(data) == true)
	{
		param_to_int(data);
		check_param_value(data);
	}
	if (error_management(data) == false)
		return (false);
	return (true);
}

bool	check_argc(t_vault *data)
{
	if (data->argc < 5 || data->argc > 6)
	{
		data->error = 1;
		return (false);
	}
	return (true);
}

bool	check_param_is_digit(t_vault *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->argv[++i])
	{
		j = -1;
		while (data->argv[i][++j])
		{
			if (ft_isdigit(data->argv[i][j]) == 1)
			{
				data->error = 1;
				return (false);
			}
		}
	}
	return (true);
}

bool	check_param_len(t_vault *data)
{
	int	i;

	i = 0;
	while (data->argv[++i])
	{
		if (ft_strlen(data->argv[i]) > 5)
		{
			data->error = 1;
			return (false);
		}
	}
	return (true);
}

void	param_to_int(t_vault *data)
{
	data->nbr_philo = ft_atoi(data->argv[1]);
	data->time_die = ft_atoi(data->argv[2]);
	data->time_eat = ft_atoi(data->argv[3]);
	data->time_sleep = ft_atoi(data->argv[4]);
	if (data->argc == 6)
		data->nbr_time_eat = ft_atoi(data->argv[5]);
}

