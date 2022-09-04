/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_pipe_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:42:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 18:37:13 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_pipe_1(int i, t_data *data, t_process *tmp)
{
	if (!ft_cmd(tmp->cmd, "pwd"))
		return (ft_pwd(data->fd[(data->c_n + 1) * 2 + 1]));
	if (!ft_cmd(tmp->cmd, "env"))
		return (ft_cmd_env(data, data->fd[(data->c_n + 1) * 2 + 1]));
	if (!ft_cmd(tmp->cmd, "cd"))
		return (ft_cd(data, data->p_ag[i],
				data->fd[(data->c_n + 1) * 2 + 1]));
	if (!ft_cmd(tmp->cmd, "echo"))
		return (ft_echo(data->p_ag[i], data->fd[(data->c_n + 1) * 2 + 1]));
	return (0);
}
