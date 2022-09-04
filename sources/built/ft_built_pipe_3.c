/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_pipe_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:09:47 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 18:39:55 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_pipe_3(int i, t_data *data, t_process *tmp)
{
	if (!ft_cmd(tmp->cmd, "pwd"))
		return (ft_pwd(data->file[i]));
	if (!ft_cmd(tmp->cmd, "env"))
		return (ft_cmd_env(data, data->file[i]));
	if (!ft_cmd(tmp->cmd, "cd"))
		return (ft_cd(data, data->p_ag[i], data->file[i]));
	if (!ft_cmd(tmp->cmd, "echo"))
		return (ft_echo(data->p_ag[i], data->file[i]));
	return (0);
}
