/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:37 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:51:20 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_one(int i, t_data *data, t_process *tmp, char **str)
{
	i = 0;
	(void)str;
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
