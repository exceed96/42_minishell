/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:48:59 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 17:14:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_6(t_data *data, t_process *tmp, char **senv, int i)
{
	(void)senv;
	if (dup2(data->fd[data->c_n * 2], STDIN_FILENO) == -1)
		ft_perror("dup2 input failed in pipe_process", 1);
	if (!data->inout->next || (data->inout->next
			&& data->inout->next->type != 1))
	{
		if (ft_built_pipe_3(i, data, tmp))
			exit(0);
		if (dup2(data->file[i], STDIN_FILENO) == -1)
			ft_perror("dup2 input failed in pipe_process", 1);
		if (data->inout->next)
			if (dup2(data->fd[data->c_n * 2 + 1], STDOUT_FILENO) == -1)
				ft_perror("dup2 input failed in pipe_process", 1);
	}
	if (!data->inout->next || tmp->output_fd)
	{
		if (ft_built_pipe_1(i, data, tmp))
			exit(0);
		if (dup2(data->fd[(data->c_n + 1) * 2 + 1], STDOUT_FILENO) == -1)
			ft_perror("dup2 output failed in pipe_process", 1);
	}
}	
