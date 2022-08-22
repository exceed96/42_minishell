/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:15:07 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/22 18:38:34 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdio.h>

char	*ft_export_env(char **env)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup(env[0]);
	while (env[i])
	{
		str = ft_strnjoin(str, "\n", 1);
		str = ft_strnjoin(str, env[i], ft_strlen(env[i]));
		i++;
	}
	return (str);
}

void	ft_change_shlvl(char **env)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = NULL;
	str1 = ft_search_env(*env, "SHLVL");
	if (str1)
	{
		i = ft_atoi(str1);
		i++;
		free(str1);
		str1 = ft_itoa(i);
		ft_remove_env_search(env, "SHLVL", -1, 0);
		str2 = ft_strjoin("SHLVL=", str1);
		free(str1);
		(*env) = ft_strnjoin((*env), "\n", 1);
		(*env) = ft_strnjoin((*env), str2, (int)ft_strlen(str2));
		free(str2);
	}
}

int	main(int ac, char **ag, char **envp)
{
	char	*ev;

	(void)ac;
	(void)ag;
	if (!envp[0])
		ev = ft_strdup("MINISHELL=1");
	else
		ev = ft_export_env(envp);
	printf("%s", ev);
	ft_change_shlvl(&ev);
	printf("%s", ev);
}
