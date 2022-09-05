/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:34:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:24:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_one_process(t_data *data, t_process *tmp, char **senv, char **str)
{
	data->pid1[0] = fork();
	if (data->pid1[0] < 0)
		ft_fork_error(data, 1, "fork failed\n");
	if (!data->pid1[0])
	{
		data->p_paths[0] = ft_check_ag(tmp->cmd, senv);
		ft_close_pipes(data);
		if (execve(data->p_paths[0], str, senv) == -1)
			ft_perror("zsh: unable to perform this command", 1);
	}
}
