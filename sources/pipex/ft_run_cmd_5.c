/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:35:03 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 13:20:24 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_5(t_process *tmp, t_data *data, int i, char **senv)
{
	char	**str;
	int		c;
	
	str = ft_search_quote(ft_env_split(tmp->cmd_arg, ' '), 0, 0);
	c = ft_built_one(0, data, tmp, str);
	if (!c)
		ft_one_process(0, tmp, senv, str);
	else
	{
		if (c == 2)
			data->status = 1;
		else
			data->status = 0;
		ft_free_split(str);
		ft_free_exec(data, i);
		return (0);
	}
	ft_free_split(str);
	data->j = 0;
	return (1);
}
