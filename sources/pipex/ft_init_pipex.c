/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:06:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 15:31:50 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_init_pipex(t_data *data, int i)
{
	int	x;

	x = -1;
	data->line = NULL;
	data->fd = (int *)malloc(sizeof(int) * (i * 2));
	if (!data->fd)
		return (0);
	data->p_ag = malloc(sizeof(char **) * i);
	if (!data->p_ag)
		return (0);
	data->p_paths = malloc(sizeof(char *) * i);
	if (!data->p_paths)
		return (0);
	data->file = malloc(sizeof(int) * i);
	if (!data->file)
		return (0);
	data->set[0] = '\'';
	data->set[1] = '\"';
	data->set[2] = ' ';
	data->set[3] = '\0';
	data->n_cmd = i;
	data->pid1 = malloc(sizeof(pid_t) * i);
	return (1);
}
