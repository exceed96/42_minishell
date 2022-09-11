/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:25:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 12:27:32 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env_var(char *ag, char **env, int q[2])
{
	int	len;

	q[1] = 0;
	len = ft_strchr_r(ag, '=');
	if (len == -1)
		return (-1);
	while (env[q[1]])
	{
		if (!ft_strncmp(env[q[1]], ag, len + 1))
			return (1);
		q[1]++;
	}
	return (0);
}
