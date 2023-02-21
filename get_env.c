/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:06:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 12:18:40 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_grep(char *test)
{
	char	*path;
	int		i;
	int		j;

	j = 0;
	i = 0;
	path = "PATH";
	while (path[i])
	{
		if (path[i] == test[i])
			j++;
		i++;
	}
	return (j);
}

char	**get_env(char **env)
{
	char	*path;
	char	**result;
	int		i;

	i = 0;
	path = NULL;
	while (env[i] && !path)
	{
		if (ft_grep(env[i]) == 4)
		{
			path = ft_strdup(env[i] + 5);
			if (!path)
				return (NULL);
		}
		i++;
	}
	result = ft_split(path, ':');
	if (!result)
		free_split(result);
	return (free(path), result);
}