/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:46:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:32:54 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_check_ag(char *cmd, char **senv)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = ft_search_quote_2(ft_strdup(cmd), 0);
	if (!access(tmp, F_OK))
	{
		if (ft_strlen(tmp) > 2 && tmp[0] == '.'
			&& tmp[1] == '/' && !access(tmp, X_OK))
			return (tmp);
		else
			if (ft_strchr(tmp, '/'))
				ft_perror("Permission Denied\n", 126);
	}
	if (ft_strchr(tmp, '/'))
		ft_perror("zsh: no such file or directory", 127);
	tmp = ft_strsjoin("/", tmp, ft_strlen(tmp));
	if (ft_find_path(senv) == -1)
		ft_perror("zsh: no such file or directory", 127);
	else
		tmp2 = ft_check_ag_2(senv, tmp, ft_find_path(senv));
	free(tmp);
	if (!tmp2)
		ft_perror("zsh: command not found", 127);
	return (tmp2);
}
