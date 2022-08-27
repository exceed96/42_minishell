/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:26:42 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 15:57:16 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_default(char **cmd, int *i, int j, char *env)
{
	char	*tmp;
	char	*var;
	int		x;

	x = 0;
	while ((*cmd)[(*i) + x] && ft_env_char((*cmd)[(*i) + x]))
		x++;
	var = ft_strndup((*cmd) + (*i), x);
	(*i) += x;
	tmp = ft_search_env(env, var);
	free(var);
	if (!tmp)
	{
		tmp = ft_strndup((*cmd), j);
		tmp = ft_strnjoin(tmp, (*cmd) + (*i), ft_strlen((*cmd) + (*i)));
	}
	else
		tmp = ft_replace((*cmd), tmp, (*i), j);
	free((*cmd));
	(*cmd) = tmp;
	(*i) = j;
}
