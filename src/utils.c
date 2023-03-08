/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:54:07 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/08 15:07:16 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_vault *data, int argc, char **argv)
{
	data->argc = argc;
	data->argv = ft_dbl_ptr_copy(argv);
	data->error = 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->nbr_time_eat = 0;
	get_start_time(data);
}
