/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:42:59 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:47:09 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd(t_process *process, char **senv, char **env)
{
	int			i;
	t_data		data;
	t_process	*tmp;
	t_in_out	*tmp2;

	data.status = g_status_number;
	g_status_number = -42;
	data.p_env = env;
	tmp = process;
	tmp2 = tmp->inout;
	data.fork_status = 0;
	i = ft_run_cmd_2(tmp, tmp2, process);
	if (!ft_malloc_pipex(&data, i))
		ft_perror("--- Malloc Failed ---", 1);
	ft_create_pipes(&data);
	if (!ft_run_cmd_4(&data, tmp, senv, i))
		return (data.status);
	ft_close_pipes(&data);
	while (!data.fork_status && data.j >= 0)
	{
		waitpid(data.pid1[data.j], &data.status, 0);
		data.j--;
	}
	ft_free_exec(&data, i);
	return (ft_status(&data));
}
