/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:40:39 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 20:07:23 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_5(t_data *data, t_process *tmp, char **senv, int i)
{
	data->pid1[i] = fork();
	if (data->pid1[i] < 0)
		ft_fork_error(data, i, "fork failed\n");
	if (!data->pid1[i])
	{
		data->file[i] = open(ft_search_quote_2(data->inout->file, 0), O_RDONLY);
		if (data->file[i] < 0)
		{
			data->status = 1;
			ft_perror("zsh: no such file or directory", 1);
		}
		data->p_ag[i] = ft_search_quote(ft_env_split(tmp->cmd_arg, ' '), 0, 0);
		ft_pipe_process_6(data, tmp, senv, i);
		ft_close_pipes(data);
		close(data->file[i]);
		data->p_paths[i] = ft_check_ag(tmp->cmd, senv);
		if (tmp->cmd)
		{
			if (!data->inout->next || (data->inout->next
					&& data->inout->next->type != 1))
				if (execve(data->p_paths[i], data->p_ag[i], senv) == -1)
					ft_perror("zsh: unable to perform this command", 1);
		}
		exit (0);
	}
}
