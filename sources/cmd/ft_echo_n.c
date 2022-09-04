/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:24:05 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 14:25:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo_n(char **ag, int i, int j)
{
	if(ag[i] && ag[i][j] == '-' && ag[i][++j] == 'n')
	{
		while (ag[i][j])
		{
			if (ag[i][j] != 'n')
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}
