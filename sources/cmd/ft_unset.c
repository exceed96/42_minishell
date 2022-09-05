/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:09:38 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:46:27 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_data *data, char **ag, int fd)
{
	int		i;
	char	**tmp;
	
	(void)fd;
	i = 0;
	tmp = data->p_env;
	while (ag[++i])
	{
		if (ft_is_env(ft_search_quote_2(ag[i], 0)))
			ft_remove_env_search(tmp, ag[i], -1, 0);
		else
			printf("unset: %s not a valid env", ag[i]);
	}
	return (1);
}
