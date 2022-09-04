/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:01:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:15:42 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_find_path(char **senv)
{
	int	i;

	i = 0;
	while (senv[i])
	{
		if (!ft_strncmp(senv[i], "PATH=", 5))
			return (i);
		i++;
	}
	return (-1);
}
