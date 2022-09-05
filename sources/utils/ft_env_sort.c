/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:44:03 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 16:58:39 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_sort(char *env, int i, int j, int k)
{
	char	**r_env;

	r_env = ft_env_split(env, '\n');
	while (k)
	{
		k = 0;
		i = -1;
		while (r_env[++i])
		{
			j = 0;
			if (r_env[i + 1] && r_env[i][j] > r_env[i + 1][j])
				k = ft_env_swap(&r_env[i + 1], &r_env[i]);
			else if (r_env[i + 1] && r_env[i][j] &&
				r_env[i + 1][j] && r_env[i][j] == r_env[i + 1][j])
			{
				while (r_env[i][j] && r_env[i + 1][j] &&
						r_env[i][j] == r_env[i + 1][j])
					j++;
				if (r_env[i][j] && r_env[i + 1][j] &&
						r_env[i][j] > r_env[i + 1][j])
					k = ft_env_swap(&r_env[i + 1], &r_env[i]);
			}
		}
	}
	return (r_env);
}
