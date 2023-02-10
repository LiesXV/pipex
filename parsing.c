/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/10 16:09:33 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parsing(char **argv, t_data *args)
{
	args->file1 = ft_strdup(argv[0]);
	argv[1] = ft_strjoin(argv[1], " ");
	argv[1] = ft_strjoin(argv[1], args->file1);
	// ft_printf("file[0] : %s\n", argv[1]);
	args->cmd1 = ft_split(argv[1], ' ');
	args->cmd1[2] = ft_strdup(args->file1);
	// ft_printf("cmd1[0] : %s\n", args->cmd1[2]);
}

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

char	**get_path(char **env)
{
	char	*path;
	char	**result;
	int i;

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
	return (result);
}