/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:38:32 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/22 16:42:46 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_search_env(char *env, char *target)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i] != target[0])
			while (env[i] && env[i] != '\n')
				i++;
		else
		{
			j = 0;
			while (env[i] && j < (int)ft_strlen(target) && env[i] == target[j])
			{
				i++;
				j++;
			}
			if (j == (int)ft_strlen(target) && env[i] == '=')
				return (ft_strndup(env + i + 1), ft_len_env(env + i + 1));
		}
		i++;
	}
	return (NULL);
}
