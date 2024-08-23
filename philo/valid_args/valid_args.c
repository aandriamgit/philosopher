/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:53:33 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/22 10:55:35 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	only_digit(char *lol)
{
	int	i;

	i = 0;
	while (lol[i])
	{
		if (!ft_isdigit(lol[i]))
			return (0);
		i++;
	}
	return (1);
}
