/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_state_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:46:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 16:06:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_state_return(char **cmd, int *i, int j)
{
	char	*str;

	str = ft_itoa(g_status_number);
	(*i) += ft_strlen(str);
	str[ft_strlen(str)] = '\0';
	str = ft_replace((*cmd), str, (*i), j);
	free((*cmd));
	(*cmd) = str;
	(*i) = j;
}
