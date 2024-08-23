/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saves_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:52:08 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/23 17:51:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	find_philo_nb(t_vars vars)
{
	int	nb;

	nb = -1;
	nb++;
	nb = ft_atoi(vars.saves.argv[1]);
	return (nb);
}
