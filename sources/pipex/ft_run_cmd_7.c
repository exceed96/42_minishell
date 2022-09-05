/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:56:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:51:57 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_7(t_data *data, t_process **tmp, char **senv, int i)
{
	while (i >= 0 && (!data->inout))
	{
		ft_pipe_process(data, (*tmp), senv, i);
		if (data->fork_status == -1)
			return (-1);
		(*tmp) = (*tmp)->next;
		data->c_n++;
		i--;
		if ((*tmp))
			data->inout = (*tmp)->inout;
	}
	while (data->inout && i >= 0 && data->inout->type == 2)
	{
		ft_pipe_process_3(data, (*tmp), senv, i);
		data->inout = data->inout->next;
		if (!data->inout && !(*tmp)->output_fd && (*tmp)->cmd
			&& !ft_cmd((*tmp)->cmd, "exit"))
			exit(0);
		i--;
	}
	i = ft_run_cmd_8(data, &(*tmp), senv, i);
	return (i);
}
