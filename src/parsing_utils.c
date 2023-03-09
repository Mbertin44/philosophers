/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:32:26 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/09 11:06:42 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_param_value(t_vault *data)
{
	if (data->nbr_philo > 200 || data->nbr_philo < 1)
		data->error = 2;
	if (data->time_die < 1 || data->time_eat < 1 || data->time_sleep < 1
		|| (data->argc == 6 && data->nbr_time_eat < 1))
		data->error = 1;
}
