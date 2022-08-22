/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:34:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/22 18:00:01 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*ft_export_env(char **env);
void	ft_change_shlvl(char **env);

int		ft_len_env_wl(char *str);
int		ft_len_env_ws(char *str);
char	*ft_remove_env(char *str, int x, int y);
void	ft_remove_env_search(char **env, char *str, int i, int j);
char	*ft_search_env(char *env, char *target);

char	*ft_strndup(const char *s, size_t n);
char	*ft_strnjoin(char *s1, char *s2, int n);

#endif
