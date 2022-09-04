/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:59:59 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 15:34:17 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process(t_data *data, t_process *tmp, char **senv, int i)
{
	data->pid1[i] = fork();
	if (data->pid1[i] < 0)
		ft_fork_error(data, 1, "fork failed\n");
	if (!data->pid1[i])
	{
		data->p_ag[i] = ft_search_quote(ft_env_split(tmp->cmd_arg, ' '), 0, 0);
		ft_pipe_process_2(data, tmp, senv, i);
		ft_close_pipes(data);
		data->p_paths[i] = ft_check_ag(tmp->cmd, senv);
		if (execve(data->p_paths[i], data->p_ag[i], senv))
			ft_perror("zsh: unable to perform this command", 1);
	}
}
