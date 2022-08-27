/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:43:41 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 12:45:57 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_digit(char **cmd, int *i, int j)
{
	char	*str;

	str = ft_strndup((*cmd), (*i) - 1);
	str = ft_strnjoin(str, (*cmd) + (*i) + 1, ft_strlen((*cmd) + (*i) + 1));
	free((*cmd));
	(*cmd) = str;
	(*i) = j;
}
