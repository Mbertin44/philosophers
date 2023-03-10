/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:40:54 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/10 13:02:27 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	error_management(t_vault *data)
{
	if (data->error == 1)
		printf("Wrong parameters\n");
	else if (data->error == 2)
		printf("Wrong amount of philosophers\n");
	else if (data->error == 3)
		printf("Fail to create the philos thread\n");
	else if (data->error == 4)
		printf("Fail to join the threads\n");
	if (data->error != 0)
		return (false);
	return (true);
}

bool	join_thread(t_vault *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
		{
			data->error = 4;
			return (false);
		}
	}
	return (true);
}
