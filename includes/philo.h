/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:14 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

					/***** DEFINES *****/
# define TRUE 1
# define FALSE 0

					/***** STRUTURES *****/
typedef struct s_vault
{
	int				argc;
	char			**argv;
	int				error;
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
	long int		start_time_ms;
	long int		current_time_ms;
	struct timeval	start_time;
	struct timeval	current_time;
}	t_vault;

					/***** FONCTIONS *****/

/***** errors.c *****/
bool		error_management(t_vault *data);

/***** parsing.c *****/
bool		parsing(t_vault *data);
bool		check_argc(t_vault *data);
bool		check_param_is_digit(t_vault *data);
bool		check_param_len(t_vault *data);
void		check_param_value(t_vault *data);

/***** parsing_utils.c *****/
void		param_to_int(t_vault *data);

/***** utils.c *****/
void		init_data(t_vault *data, int argc, char **argv);

/***** get_time.c *****/
void		get_start_time(t_vault *data);
long int	get_actual_time(t_vault *data);

#endif