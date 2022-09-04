/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:01:36 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 16:08:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_4(t_data *data, t_process *tmp, char **senv, int i)
{
	int	c;

	(void)senv;
	if (dup2(data->fd[data->c_n * 2], STDIN_FILENO) == -1)
		ft_perror("dup2 input failed in pipe_process", 1);
	if (data->inout->next)
	{
		if (dup2(data->fd[data->c_n * 2 + 1], STDOUT_FILENO) == -1)
			ft_perror("dup2 output failed in pipe_process", 1);
	}
	else if (!data->inout->next)
	{
		if (ft_built_pipe_3(i, data, tmp))
			exit(0);
		if (dup2(data->file[i], STDOUT_FILENO) == -1)
			ft_perror("dup2 next input failed in pipe_process", 1);
	}
	else if (tmp->cmd && !data->inout->next)
	{
		c = ft_built_pipe_2(i, data, tmp);
		if (c == 2)
			exit (1);
		if (c == 1)
			exit (0);
	}
}
