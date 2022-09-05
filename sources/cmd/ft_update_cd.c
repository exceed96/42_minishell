/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:28:40 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 16:30:47 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_cd(char **env)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = getcwd(NULL, 0);
	ft_remove_env_search(env, "PWD", -1, 0);
	tmp = ft_strjoin("PWD=", tmp2);
	(*env) = ft_strnjoin((*env), "\n", 1);
	(*env) = ft_strnjoin((*env), tmp, ft_strlen(tmp));
	free(tmp2);
	free(tmp);
}
