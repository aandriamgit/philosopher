/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 08:34:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/24 11:39:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*thread_routine(void *vars)
{
	t_philo	*philo;

	philo = (t_philo *)vars;
	if (!philo->died)
	{
		usleep(philo->id * 99888);
		printf("000 %d has taken a fork\n", philo->id);
		if (philo->id == 7)
		{
			philo->died = 1;
			return (vars);
		}
	}
	return (vars);
}
