/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:51:01 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 15:53:39 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_env(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (str[i] && !ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			c = 1;
		if (!c && !ft_isalpha(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
