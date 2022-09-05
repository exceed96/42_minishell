/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:34:57 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:40:50 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_exec(t_data *data, int i)
{
	i = 0;
	if (data->file)
		free(data->file);
	if (data->pid1)
		free(data->pid1);
	if (data->p_paths)
		free(data->p_paths);
	if (data->p_ag)
		free(data->p_ag);
	if (data->fd)
		free(data->fd);
}
