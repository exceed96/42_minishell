/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:11:02 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 16:02:46 by sangyeki         ###   ########.fr       */
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
			printf("cd: HOME not set\n");
		else
			if (chdir(str))
				printf("cd: no such file or directory: %s\n", str);
	}
	else if (ft_strstrlen(path) == 2)
	{
		if (chdir(path[1]))
			printf("cd: no such file or directory: %s\n", path[1]);
	}
	else
		printf("cd: too many arguments\n");
	ft_update_cd(env);
	return (1);
}
