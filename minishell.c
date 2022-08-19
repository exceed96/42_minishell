/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:38:03 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/19 22:01:55 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_export_env(char **env)
{
	char	*str;
	int	i;

	i = 1;
	str = ft_strdup(env[0]);
	while(env[i])
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
	int	i;

	str1 = ft_search_env(*env, "SHLVL");
}

int main(int ac, char **ag, char **envp)
{
	char *ev;

	(void)ac;
	(void)ag;
	if(!envp[0])
		ev = ft_strdup("MINISHELL=1");
	else
		ev = ft_export_env(envp);
	ft_change_shlvl(&ev);
}
