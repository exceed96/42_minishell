/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_process_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:30:14 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 17:35:31 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pipe_process_8(t_data *data, t_process *tmp, char **senv, int i)
{
	int	c;

	(void)senv;
	if (tmp->output_fd || (tmp->inout && tmp->inout->next
			&& tmp->inout->next->type == 3))
	{
		if (ft_built_pipe_1(i, data, tmp))
			exit(0);
		if (dup2(data->fd[(data->c_n + 1) * 2 + 1], STDOUT_FILENO) == -1)
			ft_perror("dup2 input failed in fork process", 1);
	}
	else if (tmp->cmd && ft_cmd(tmp->cmd, "exit"))
	{
		write(2, "exit\n", 5);
		exit(0);
	}
	else if (tmp->cmd && !data->inout->next)
	{
		c = ft_built_pipe_2(i, data, tmp);
		if (c == 2)
			exit(1);
		if (c == 1)
			exit(0);
	}
}
