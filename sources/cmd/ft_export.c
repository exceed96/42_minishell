/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:06:06 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:41:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(t_data *data, char **ag)
{
	char	**tmp;
	char	*env;
	int		i;


	i = 0;
	env = NULL;
	tmp = data->p_env;
	if (ft_split_len(ag) == 1)
		ft_show_export(ft_env_sort(*tmp, 0, 0, 1), 0, 0, 0);
	else
	{
		while (ag[++i])
		{
			if (ft_is_env(ft_search_quote_2(ag[i], 0)))
			{
				env = ft_add_env(ag[i]);
				ft_remove_env_search(tmp, env, -1 ,0);
				ft_end_env(tmp, env);

			}
			else
				printf("export: not a valid identifier\n");
		}
	}
	return (1);
}
