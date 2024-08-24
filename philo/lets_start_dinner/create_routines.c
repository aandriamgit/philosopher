/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 08:34:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/24 09:11:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	*thread_routine(void *vars)
{
	t_philo	philo;

	philo = *(t_philo *)vars;
	printf("000\n");
	sleep(2);
	printf("philo_nb %d\n", philo.uses.philo_nb);
	printf("time_to_die %d\n", philo.uses.time_to_die);
	printf("time_to_eat %d\n", philo.uses.time_to_eat);
	printf("time_to_sleep %d\n", philo.uses.time_to_sleep);
	return (vars);
}
