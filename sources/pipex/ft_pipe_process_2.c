/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:03:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 18:32:06 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_2(t_data *data, t_process *tmp, char **senv, int i)
{
	int	c;

	(void)senv;
	if (tmp->input_fd)
	{
		if (dup2(data->fd[2 * data->c_n], STDIN_FILENO) == -1)
			ft_perror("dup2 input failed in pipe_process", 1);
	}
	if (tmp->output_fd)
	{
		if (ft_built_pipe_1(i, data, tmp))
			exit(0);
		if (dup2(data->fd[2 * (data->c_n + 1) + 1], STDOUT_FILENO) == -1)
			ft_perror("dup2 output failed in pipe_process", 1);
	}
	else
	{
		c = ft_built_pipe_2(i, data, tmp);
		if (c == 2)
			exit(1);
		if (c == 1)
			exit (0);
	}
}
