/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:19:27 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:03:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_cmd * 2)
	{
		close(data->fd[i]);
		i++;
	}
}
