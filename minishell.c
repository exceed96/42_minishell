/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:15:07 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 13:06:51 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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

int	ft_shell(char **env)
{
	char	*read_line;
	char	*cmd;
	char	**cmd_split;

	signal(SIGINT, ft_sig_c);
	signal(SIGQUIT, ft_sig_q);
	read_line = ft_readline();
	cmd = readline(read_line);
	free(read_line);
	if (!cmd)
	{
		printf("exit\n");
		return (0);
	}
	else if (ft_strlen(cmd) != 0)
	{
		add_history(cmd);
		cmd = ft_env((*env), cmd, 0 ,0);
		cmd_split = ft_env_split((*env), '\n');
		ft_resolve_cmd(cmd, cmd_split, env, *env);
		ft_free_split(cmd_split);
		free(cmd);
	}
	return (1);
}

int	main(int ac, char **ag, char **envp)
{
	char	*ev;

	(void)ac;
	(void)ag;
	g_status_number = 0;
	if (!envp[0])
		ev = ft_strdup("MINISHELL=1");
	else
		ev = ft_export_env(envp);
	ft_change_shlvl(&ev);
	while(1)
	{
		if (ft_shell(&ev))
			continue;
		else
			break;
	}
	free(ev);
	clear_history();
	return (0);
}
