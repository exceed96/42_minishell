/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:07:04 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 18:05:25 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_env(t_data *data, int fd)
{
	char	**env_str;
	char	**split_env;
	int		i;
	int		j;

	i = 0;
	env_str = data->p_env;
	split_env = ft_split(*env_str, '\n');
	while (split_env[i])
	{
		j = 0;
		while (split_env[i] && split_env[i][j] != '=')
			j++;
		if (split_env[i][j + 1] && split_env[i][j + 1] != '\n')
			ft_putendl_fd(split_env[i], fd);
		i++;
	}
	ft_free_split(split_env);
	return (1);
}
