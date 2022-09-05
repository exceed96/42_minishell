/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_tild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:53:39 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 12:57:38 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_tild(char **cmd, int *i, char *env)
{
	char	*str1;
	char	*str2;

	str1 = ft_search_env(env, "HOME");
	str2 = ft_strndup((*cmd), (*i)++);
	if (str1 && ft_strlen(str1))
	{
		str2 = ft_strnjoin(str2, str1, ft_strlen(str1));
		str2 = ft_strnjoin(str2, (*cmd) + (*i), ft_strlen(*cmd) + (*i));
	}
	else
		str2 = ft_strnjoin(str2, (*cmd) + (*i), ft_strlen((*cmd) + (*i)));
	free((*cmd));
	(*cmd) = str2;
	free(str1);
}
