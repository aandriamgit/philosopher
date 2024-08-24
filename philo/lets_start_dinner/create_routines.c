/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 08:34:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/24 10:01:14 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*thread_routine(void *vars)
{
	t_philo	philo;

	philo = *(t_philo *)vars;
	usleep(philo.id * 999888);
	printf("000 %d has taken a fork\n", philo.id);
	if (philo.id == 66)
		philo.died = 1;
	return (vars);
}
