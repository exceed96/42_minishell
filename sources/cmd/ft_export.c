/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:21:16 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:06 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(t_data *data)
{
	int		q[3];
	int		r_n;
	char	**str;

	q[2] = 1;
	str = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(str) >= 2)
	{
		q[0] = 1;
		while (str[q[0]])
		{
			r_n = ft_env_var(str[q[0]], data->env, q);
			if (r_n == -1)
				return (1);
			if (r_n == 1)
			{
				free(data->env[q[1]]);
				data->env[q[1]] = ft_strdup(str[q[0]++]);
			}
			else if (!r_n)
				data->env = ft_extend_split(data->env, str[q[0]++]);
			q[2]++;
		}
	}
	return (0);
}
