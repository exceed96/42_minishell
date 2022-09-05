/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:09 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:27:16 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_end_env(char **tmp, char *env)
{
	if ((*tmp)[ft_strlen(*tmp) - 1] != '\n')
		(*tmp) = ft_strnjoin(*tmp, "\n", 1);
	(*tmp) = ft_strnjoin(*tmp, env, ft_strlen(env));
	if (env)
		free(env);
}
