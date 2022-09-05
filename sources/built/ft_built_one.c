/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:37 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:47:03 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_one(int i, t_data *data, t_process *tmp, char **str)
{
	i = 0;
	if (!ft_cmd(tmp->cmd, "pwd"))
		return (ft_pwd(1));
	if (!ft_cmd(tmp->cmd, "env"))
		return (ft_cmd_env(data, 1));
	if (!ft_cmd(tmp->cmd, "cd"))
		return (ft_cd(data, str, 1));
	if (!ft_cmd(tmp->cmd, "echo"))
		return (ft_echo(str, 1));
	if (!ft_cmd(tmp->cmd, "unset"))
		return (ft_unset(data, str, 1));
	if (!ft_cmd(tmp->cmd, "export"))
		return (ft_export(data, str));
	return (0);
}
