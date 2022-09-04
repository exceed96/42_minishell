/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:10:44 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:57:22 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_run_cmd_11(t_data *data, t_process *tmp, char **senv, int i)
{
	ft_pipe_process_9(data, tmp, senv, i);
	data->inout = data->inout->next;
	if (!data->inout && !tmp->output_fd && tmp->cmd
		&& ft_cmd(tmp->cmd, "exit"))
		exit(0);
}
