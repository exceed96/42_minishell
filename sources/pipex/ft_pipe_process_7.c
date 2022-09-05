/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:22:34 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 20:07:44 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_7(t_data *data, t_process *tmp, char **senv, int i)
{
	(void)senv;
	data->pid1[i] = fork();
	if (data->pid1[i] < 0)
		ft_fork_error(data, 1, "fork error\n");
	if (!data->pid1[i])
	{
		data->p_ag[i] = ft_search_quote(ft_env_split(tmp->cmd_arg, ' '), 0, 0);
		if (dup2(data->fd[(data->c_n + 1) * 2 - 2], STDIN_FILENO) == -1)
			ft_perror("dup2 input failed in fork process", 1);
		ft_pipe_process_8(data, tmp, senv, i);
		ft_close_pipes(data);
		if (tmp->cmd && data->inout->next)
		{
			data->p_paths[i] = ft_check_ag(tmp->cmd, senv);
			if (execve(data->p_paths[i], data->p_ag[i], senv) == -1)
				ft_perror("zsh: unable to perform this command", 1);
		}
		exit(0);
	}
}
