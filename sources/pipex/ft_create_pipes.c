/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:28:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 15:30:08 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_create_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_cmd)
	{
		if (pipe(data->fd + 2 * i) < 0)
			ft_perror("--- Create pipes Error!! ---", 1);
		i++;
	}
}
