/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_pipe_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:49:45 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 18:38:00 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_pipe_2(int i, t_data *data, t_process *tmp)
{
	if (!ft_cmd(tmp->cmd, "pwd"))
		return (ft_pwd(1));
	if (!ft_cmd(tmp->cmd, "env"))
		return (ft_cmd_env(data, 1));
	if (!ft_cmd(tmp->cmd, "cd"))
		return (ft_cd(data, data->p_ag[i], 1));
	if (!ft_cmd(tmp->cmd, "echo"))
		return (ft_echo(data->p_ag[i], 1));
	return (0);
}
