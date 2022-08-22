/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_env_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:53:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/22 17:34:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_remove_env_search(char **env, char *str, int i, int j)
{
	while ((*env)[i++])
	{
		if ((*env)[i] != str[0])
			while ((*env)[i] && (*env)[i] != '\n')
				i++;
		else
		{
			j = 0;
			while ((*env)[i] && j < (int)ft_strlen(str)
					&& (*env)[i] == str[j] && str[j++] != '=')
				i++;
			if (j == (int)ft_len_env_ws(str) && (*env)[i] == '=')
			{
				j = i - j;
				while ((*env)[i] && (*env)[i] != '\n')
					i++;
				(*env) = ft_remove_env((*env), i, j);
				return ;
			}
		}
		if (!(*tmp)[i])
			break ;
	}
}
