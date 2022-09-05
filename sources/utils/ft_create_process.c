/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:09:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 14:31:33 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_process	*ft_create_process(int i, int j, char **cmd)
{
	t_process	*process;
	t_process	*tmp;

	while (cmd[++i])
	{
		ft_first_process(&process, &tmp, i);
		j = ft_n_cmd(&process, cmd, i, 0);
		while (cmd[i][j])
		{
			j += ft_n_space(cmd[i] + j);
			if (cmd[i][j] == '>' || cmd[i][j] == '<')
				ft_direction(&process, i, &j, cmd);
			else if (cmd[i][j])
			{
				process->cmd_arg = ft_strnjoin(process->cmd_arg, cmd[i] + j,
						ft_quote_len(cmd[i] + j));
				process->cmd_arg = ft_strnjoin(process->cmd_arg, " ", 1);
				j += ft_quote_len(cmd[i] + j);
			}
		}
		if (cmd[i + 1])
			process->type = ft_strdup("|");
	}
	ft_free_split(cmd);
	return (tmp);
}
