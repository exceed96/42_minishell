/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:21:16 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 12:25:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(t_data *data)
{
	int		q[2];
	int		len;
	char	**str;

	str = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(str) >= 2)
	{
		q[0] = 1;
		while (str[q[0]])
		{
			len = ft_env_var(str[q[0]], data->env, q);
			if (len == 1)
			{
				free(data->env[q[1]]);
				data->env[q[1]] = ft_strdup(str[q[0]]);
			}
			else if (!len)
				data->env = ft_extend_split(data->env, str[q[0]]);
			q[0]++;
		}
	}
	return (0);
}
