/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:55:26 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 20:04:19 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_3(t_data *data, t_process *tmp, char **senv, int i)
{
	data->pid1[i] = fork();
	if (data->pid1[i] < 0)
		ft_fork_error(data, 1, "fork error\n");
	if (!data->pid1[i])
	{
		data->p_ag[i] = ft_search_quote(ft_env_split(tmp->cmd_arg, ' '), 0, 0);
		data->file[i] = open(ft_search_quote_2(data->inout->file, 0),
				O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (data->file[i] < 0)
			ft_perror("zsh: file creation failed", 1);
		ft_pipe_process_4(data, tmp, senv, i);
		ft_close_pipes(data);
		data->p_paths[i] = ft_check_ag(tmp->cmd, senv);
		if (tmp->cmd)
		{
			if (!data->inout->next)
				if (execve(data->p_paths[i], data->p_ag[i], senv) == -1)
					ft_perror("zsh: unable to perform this command", 1);
		}
		exit(0);
	}
}
