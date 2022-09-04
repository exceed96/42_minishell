/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:52:24 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:39:23 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// 1 over cmds
void	ft_run_cmd_6(t_data *data, t_process *tmp, char **senv, int i)
{
	t_in_out	*tmp_inout;

	while (i >= 0)
	{
		if (!data->inout)
			data->inout = tmp->inout;
		i = ft_run_cmd_7(data, &tmp, senv, i);
		if (i >= 0 && data->inout && data->inout->type == 3)
		{
			tmp_inout = data->inout;
			ft_run_cmd_9(data, tmp_inout);
			ft_run_cmd_10(data, &tmp, senv, i);
			i--;
		}
		if (i >= 0 && data->inout && data->inout->type == 4)
		{
			ft_run_cmd_11(data, tmp, senv, i);
			i--;
		}
		if (i >= 0 && data->inout && tmp && !data->inout)
		{
			tmp = tmp->next;
			data->c_n++;
		}
	}
}
