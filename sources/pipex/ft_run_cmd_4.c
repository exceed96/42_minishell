/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:32:06 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:39:36 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_4(t_data *data, t_process *tmp, char **senv, int i)
{
	t_process	*process;

	process = tmp;
	if (i == 1 && !tmp->inout)
	{
		if (ft_run_cmd_5(tmp, data, i, senv) != 1)
			return (0);
	}
	else
	{
		i--;
		data->j = i;
		data->inout = NULL;
		data->c_n = 0;
		ft_run_cmd_6(data, tmp, senv, i);
	}
	return (1);
}
