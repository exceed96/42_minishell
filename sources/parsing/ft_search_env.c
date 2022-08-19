/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:54:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/19 12:11:31 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_search_env(char *env, char *target)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i] != target[0])
			while (env[i] && env[i] != '\n') //개행구분
				i++;
		else
		{
			j = 0;
			while(env[i] && j < (int)ft_strlen(target) && env[i] == target[j])
			{
				i++;
				j++;
			}
			if (j == (int)ft_strlen(target) && env[i] == '=')
				return (ft_strndup(env + x + 1), )
		}
		i++;
	}
	return (NULL);
}
