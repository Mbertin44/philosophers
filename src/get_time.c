/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:45:22 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/15 14:55:04 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_start_time(t_vault *data)
{
	gettimeofday(&data->start_time, NULL);
	data->start_time_ms = (data->start_time.tv_sec * 1000)
		+ (data->start_time.tv_usec / 1000);
}

long int	get_actual_time(t_vault *data)
{
	gettimeofday(&data->current_time, NULL);
	data->current_time_ms = (data->current_time.tv_sec * 1000)
		+ (data->current_time.tv_usec / 1000);
	return (data->current_time_ms - data->start_time_ms);
}

void	fixed_usleep(int time_to_sleep, t_vault *data)
{
	int	start_sleep;
	int	sleeping_time;

	start_sleep = get_actual_time(data);
	while (1)
	{
		sleeping_time = get_actual_time(data) - start_sleep;
		if (sleeping_time >= time_to_sleep)
			break ;
		usleep(500);
	}
}