/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:11:02 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 18:35:57 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(t_data *data, char **path, int fd)
{
	char	**env;
	char	*str;

	(void)fd;
	env = data->p_env;
	if (ft_strstrlen(path) == 1)
	{
		str = ft_search_env(*env, "HOME");
		if (!ft_strlen(str) || !str)
			ft_putstr_fd("cd: HOME not set\n", 2);
		else
			if (chdir(str))
				ft_putstr_fd("cd: no such file or directory\n", 2);
	}
	else if (ft_strstrlen(path) == 2)
	{
		if (chdir(path[1]))
			ft_putstr_fd("cd: not a directory\n", 2);
	}
	else
		ft_putstr_fd("cd: too many arguments\n", 2);
	ft_update_cd(env);
	return (1);
}
