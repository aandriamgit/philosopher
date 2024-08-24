/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 08:34:27 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/24 11:35:16 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*thread_routine(void *vars)
{
	t_philo	*philo;

	philo = (t_philo *)vars;
	if (philo->id == 76)
		philo->died = 1;
	if (!philo->died)
	{
		usleep(philo->id * 99888);
		printf("000 %d has taken a fork\n", philo->id);
	}
	if (philo->died)
		return (vars);
	return (vars);
}
